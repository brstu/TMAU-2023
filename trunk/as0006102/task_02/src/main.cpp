#include <iostream>
#include <cmath>
#include <array>
using namespace std;


/**
  \brief Класс абстрактной модели
  
  Модель используется для представления других моделей
 */
class Model {
public:

    /**
     \brief Виртуальная функция для определения температуры
     \param current_temp: 
     \param control_var: Температуры на входе
     \return Температуры на выходе
    */
    virtual double simulate_temperature(double current_temp, double control_var) = 0;

    virtual ~Model() = default;
};



/**
 \brief Линейная модель контроля температуры
 */
class Linear_Model : public Model {
private:
    double alpha; // Параметр alpha
    double beta; // Параметр beta
public:
    /**
    \brief Строит новый объект Linear_Model
    \param alpha: Константа
    \param beta: Константа
    */
    Linear_Model(double alpha, double beta) : alpha(alpha), beta(beta) {}

    /**
    \brief Метод расчета выходной температуры объекта линейной модели
    */
    double simulate_temperature(double current_temp, double control_var) final {
        return alpha * current_temp + beta * control_var;
    }

    /**
    \brief Удаляет объект Linear_Model
    */
    ~Linear_Model() override = default;
};

/**
 \brief Нелинейная модель контроля температуры
 */
class Nonlinear_Model : public Model {
private:
    double alpha; /// Параметр alpha
    double beta; /// Параметр beta
    double gamma; /// Параметр gamma
    double delta; /// Параметр delta

    double prev_temp = 0;

    double prev_control_var = 0;
public:

    /**
    \brief Строит новый объект Nonl_inearModel
    \param alpha: Константа
    \param beta: Константа
    \param gamma: Константа
    \param delta: Константа
    */
    Nonlinear_Model(double alpha, double beta, double gamma, double delta) :
        alpha(alpha),
        beta(beta),
        gamma(gamma),
        delta(delta) {}

    /**
    \brief Метод расчета выходной температуры объекта нелинейной модели
    */
    double simulate_temperature(double current_temp, double control_var) final {
        double calc = alpha * current_temp - beta * pow(prev_temp, 2) + gamma * control_var + delta * sin(prev_control_var);
        prev_temp = current_temp;
        prev_control_var = control_var;
        return calc;
    }
    /**
    \brief Удаляет объект NonlinearModel
    */
    ~Nonlinear_Model() override = default;
};


/**
\brief Пропорциональный интегрально-производный регулятор
 */
class PID_regulator
{
private:
    /// Коэффициент передачи
    const double K = 0.1;
    /// Константа интегрирования
    const double T = 10;
    /// Константа дифференцирования
    const double TD = 80;
    /// Шаг квантования
    const double T0 = 50;
    // Время моделирования
    const double simulation_time = 30;
    /// Значение управляющей переменной
    double Uk = 0;


    /**
    \brief Расчет текущих контрольных значения
    \param errors: Массив ошибок
    \return double updated значение переменной управления
    */
    double calculate_Uk(double error)
    {
        /// используем массив для хранения ошибок и цикл для вычисления Uk
        array<double, 3> errors = { 0, 0, 0 }; /// хранение последних трех ошибок
        errors[2] = errors[1]; /// сдвиг ошибок влево
        errors[1] = errors[0];
        errors[0] = error; /// хранение текущей ошибки

        /// коэффициенты для формулы PID
        array<double, 3> q = { K * (1 + TD / T0), -K * (1 + 2 * TD / T0 - T0 / T), K * TD / T0 };

        /// цикл по ошибкам и добавление их произведений с коэффициентами к Uk
        for (int i = 0; i < 3; i++) {
            Uk += q[i] * errors[i];
        }

        return Uk;
    }

public:
    /**
    \brief Регулятор моделирования
    \param desired_temp: Требуемое значение
    \param initial_temp: Начальная температура
    \param model: Линейная или нелинейная модель
 */
    void Regulate(double desired_temp, double initial_temp, Model& model)
    {

        double actual_temp = initial_temp;
        for (int i = 1; i <= simulation_time; i++) {
            double error;
            error = desired_temp - actual_temp;
            Uk = calculate_Uk(error);
            actual_temp = model.simulate_temperature(initial_temp, Uk);
            cout << "E = " << error << "\t"
                <<"Yt = " << actual_temp << "\t"
                <<"Uk = " << Uk << endl;

        }
        Uk = 0;
    }
};
    /**
    \brief Ввод параметров для моделирования
    \param alpha: Конастанта
    \param beta: Конастанта
    \param gamma: Конастанта
    \param delta: Конастанта
    \param is_nonlinear_Model: Тип модели
 */
void input_parametrs(double& alpha, double& beta, double& gamma, double& delta, bool is_nonlinear_Model) {

    /// массив для хранения параметров и цикл для их ввода
    array<const char*, 4> names = { "alpha", "beta", "gamma", "delta" }; // названия параметров
    array<const int, 3> num_params = { 2, 4 }; // количество параметров для каждого типа модели
    int n = num_params[is_nonlinear_Model]; // получение количества параметров в зависимости от типа модели

    /// создание массива для хранения параметров по ссылке
    array<double*, 4> params = { &alpha, &beta, &gamma, &delta };

    /// цикл по параметрам и их ввод с использованием их названий
    for (int i = 0; i < n; i++) {
        cout << "Input " << names[i] << "-parameter: ";
        cin >> *(params[i]);
    }
}
int main() {

    struct ModelParams {
        double alpha;
        double beta;
        double gamma;
        double delta;
    };

    array<const char*, 2> model_names = { "Linear Model", "Nonlinear Model" }; /// названия моделей
    ModelParams model_params[2]; /// массив для хранения параметров модели

    /// цикл по моделям и ввод их параметров
    for (int i = 0; i < 2; i++) {
        cout << "----------Input " << model_names[i] << "'s constant parameters----------" << endl;
        input_parametrs(model_params[i].alpha, model_params[i].beta, model_params[i].gamma, model_params[i].delta, i);
    }

    /// создание моделей с использованием параметров
    Linear_Model linear_model{ model_params[0].alpha, model_params[0].beta };
    Nonlinear_Model nonlinear_model{ model_params[1].alpha, model_params[1].beta, model_params[1].gamma, model_params[1].delta };

    PID_regulator pid_regulator;

    /// Исправленные ошибки: добавлены пропущенные объявления для desired_temp и initial_temp
    const double desired_temp = 8;
    const double initial_temp = 3;

    cout << "\t----------Linear Model----------" << endl;
    pid_regulator.Regulate(desired_temp, initial_temp, linear_model);
    cout << endl;

    cout << "\t----------Nonlinear Model----------" << endl;
    pid_regulator.Regulate(desired_temp, initial_temp, nonlinear_model);
}
