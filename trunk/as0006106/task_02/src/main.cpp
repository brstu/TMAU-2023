#include <iostream>
#include <cmath>

/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Карпович Илья Владимирович. АС-61
*/

using namespace std;
/**
 * \brief Обстрактный класс модели
 *
 * Модель используется для представления других моделей
 */
class Model{
public:
    /**
     * @brief Виртуальная функция для определения температуры
     * 
     * @param Yt: Входная температура
     * @param Uw: Входное количество тепло
     * @return double Выходная информация о температуре
     * 
     */
    virtual double simulate_temperature(double Yt, double Uw) = 0;

    /**
     * @brief Деструктор модели
     * 
     */
    virtual ~Model() = default;
};

/**
 * @brief Линейная модель контроля температуры
 * 
 */
class LinearModel : public Model {
private:
    double a; ///< Параметр a
    double b; ///< Параметр b
public:
    /**
     * @brief Конструктор класса LinearModel
     * 
     * @param a,b: some constants 
     * 
     */
    LinearModel(double a, double b): a(a), b(b) {}
    
    /**
     * @brief Этот переопределенный метод возвращает значение температуры по Линейной симуляци
     */
    double simulate_temperature(double Yt, double Uw) final {
        return a*Yt + b*Uw;
    }

    /**
     * @brief Деструктор для класса LinearModel
     */
    ~LinearModel() override = default;
};

/**
 * @brief Линейная модель контроллера температуры
 * 
 */
class NonlinearModel : public Model {
private:
    //! Предыдущее значение температуры
    double PreYt = 0;
    //! Предыдущее значение количества теплоты 
    double PreUw = 0;
    double a; ///< Parametr a
    double b; ///< Parametr b
    double c; ///< Parametr c
    double d; ///< Parametr d

public:

    /**
     * @brief Этот переопределенный метод для определения температуры по Нелинейной модели
     */
    double simulate_temperature(double Yt, double Uw) final {
        double calc = a*Yt - b*pow(PreYt, 2) + c*Uw + d*sin(PreUw);
        PreYt = Yt;
        PreUw = Uw;
        return calc;
    }
    /**
     * @brief Конструктор класса NonLinearModel
     * @param a,b,c,d: some constants
     */
    NonlinearModel(double a, double b, double c, double d):
        a(a),
        b(b),
        c(c),
        d(d) {}

    /**
     * @brief Destroy the NonlinearModel object
     * 
     */
    ~NonlinearModel() override = default;
};


void input_parametrs(double& a, double& b, double& c, double& d, bool is_nonlinearModel) {

    if (is_nonlinearModel) {
        cout << "Введите параметр с: "; cin >> c;
        cout << "Введите параметр d: "; cin >> d;
    }
    cout << "Введите параметр а: "; cin >> a;
    cout << "Введите параметр d: "; cin >> b;


/**
 * @brief Proportional–integral–derivative регулятор
 */
class PIDregulator
{
private:
    //! Шаг квантования константный
    const double T0 = 50;
    //! Время моделирования
    const double numOfTimeModeling = 30;
    //! Значение управляющей переменной
    double Uk = 0;
    //! Коэффициент передачи
    const double K = 0.1;
    //! Константа интегрирования
    const double T = 10;
    //! Константа дифференциации
    const double TD = 80;

    /**
     * @brief Рассчитать текущее контрольное значение
     * 
     * @param e отклонение от желаемого значения
     * @param e1 предыдущее отклонение от желаемого значения
     * @param e2 предыдущее отклонение от e1
     * @return double обновляет значение управляющей переменной
     */
    double calculate_Uk(double e, double e1, double e2)
    {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        double q2 = K * TD / T0;
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:

    /**
     * @brief Регулятор моделирования
     * 
     * @param w желаемое значение
     * @param y0 начальная температура
     * @param model линейная или нелинейная модель
     */
    void Regulate(double w, double y0, Model& model)
    {  
        double e2 = 0;
        double y = y0;
        double e1 = 0;

        for (int i = 1; i <= numOfTimeModeling; i++) {
            double e;
            e = w - y;
            Uk = calculate_Uk(e, e1, e2);
            y = model.simulate_temperature(y0, Uk);
            cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << std::endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};



}
int main() {
    setlocale(LC_ALL, "Russian");
    const double w = 8;

    const double y0 = 3;

    double a;

    double b;

    double c;

    double d;


    cout << "---Пожалуйста введите параметры линейной модели---" << endl;
    input_parametrs(a,b,c,d,false);
    LinearModel linear_model{a,b};


    cout << "---Пожалуйста введите параметры нелинейной модели---" << endl;
    input_parametrs(a,b,c,d,true);
    NonlinearModel nonlinear_model{a,b,c,d};




    PIDregulator pid_regulator;



    cout << "\t---Нелинейная модель---" << endl;
    pid_regulator.Regulate(w, y0, nonlinear_model);



    cout << "\t---Линейная модель---" << endl;
    pid_regulator.Regulate(w, y0, linear_model);
    cout << endl;
    system("Pause");
    return 0;
}



    
