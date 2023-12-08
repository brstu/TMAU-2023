#include <iostream>
#include <cmath>
#include <fstream>

/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Чугарин Даниил Александрович. АС-61
*/

/**
* \class AbstractModelPID
* \brief Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
*
* Абстрактный класс, который предоставляет виртуальную функцию уравнения calculate_pid_model
* и от которого наследуются классы LinearModelPID и NonlinearModelPID
*/
class AbstractModelPID
{
public:
    virtual ~AbstractModelPID() = default;

    /**
    * \brief Виртуальная функция, переопределенная в дочерних классах LinearModelPID и NonlinearModelPID
    *
    * Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели.
    * \param curr_temp Температура помещения
    * \param warm_input Входящее тепло
    */
    virtual double calculate_pid_model(double curr_temp, double warm_input) = 0;
};


/**
* \class NonlinearModelPID
* \brief Класс, который служит для реализации нелинейной модели
*
* Дочерний класс от AbstractModelPID, который реализует нелинейную модель через переопределённую функцию calculate_pid_model
*/
class NonlinearModelPID : public AbstractModelPID
{
private:
    double a_;         ///< Коэффициент
    double b_;         ///< Коэффициент
    double c__;         ///< Коэффициент
    double d_;         ///< Коэффициент
    double prevY__ = 0; ///< Предыдущая температура 
    double nextY__;     ///< Получаемая нами температура
    double prevW__ = 0; ///< Предыдущее тепло



public:

    NonlinearModelPID(double a, double b, double c, double d, double yNext) :
        a_(a), b_(b), c__(c), d_(d), nextY__(yNext)
    { }

    /**
    * Переопределённый метод для рассчёта нелинейной модели
    *
    * Код:
    * \code
    * nextY__ = a_ * curr_temp - b_ * pow(prevY__, 2) + c__ * warm_input + d_ * sin(prevW__);
    * prevY__ = nextY__;
    * prevW__ = warm_input;
    * return nextY__;
    * \endcode
    */

    double calculate_pid_model(double curr_temp, double warm_input) override{
        nextY__ = a_ * curr_temp - b_ * pow(prevY__, 2) + c__ * warm_input + d_ * sin(prevW__);
        prevY__ = curr_temp;
        prevW__ = warm_input;
        return nextY__;
    }
};


/**
* \class LinearModelPID
* \brief Класс, который служит для реализации линейной модели
*
* Дочерний класс от AbstractModelPID, который реализует линейную модель через переопределённую функцию calculate_pid_model
*/
class LinearModelPID : public AbstractModelPID
{
private:

    double a_;     ///< Коэффициент
    double b_;     ///< Коэффициент
    double nextY__; ///< Получаемая нами температура

public:
    LinearModelPID(double a, double b, double yNext) :
        a_(a), b_(b), nextY__(yNext)
    { }

    /**
    * Переопределённый метод для рассчёта линейной модели
    *
    * Код:
    * \code
    * nextY__ = a_ * curr_temp + b_ * warm_input;
    * return nextY__;
    * \endcode
    */

    double calculate_pid_model(double curr_temp, double warm_input) override{
        nextY__ = a_ * curr_temp + b_ * warm_input;
        return nextY__;
    }
};

/**
* \class Regulator
* \brief Класс регулятора
*
* Отдельный класс, в котором мы моделируем регулятор
*/

class Regulator
{
private:

    double const_int_;      ///< Постоянная интегрирования
    double step_kvant_;     ///< Шаг для квантования
    double const_difer_;     ///< Постоянная дифференцирования
    double koev_peredach_;      ///< Коэффициент передачи
    double setpoint_ = 0; ///< Текущее значение управляющего воздействия

    double calc__uk(double ekb_1, double ekb_2, double ekb_3){
        /**
        * \brief Метод для рассчёта setpoint_
        *
        * Метод рассчёта текущего значения управляющего воздействия на объект управления
        *
        * Код:
        * \code
        * 
        * double q1 = koev_peredach_ * (1 + const_difer_ / step_kvant_);
        * double q2 = -koev_peredach_ * (1 + 2 * const_difer_ / step_kvant_ - step_kvant_ / const_int_);
        * double q3 = koev_peredach_ * const_difer_ / step_kvant_;
        * setpoint_ += (q1 * ekb_1 + q2 * ekb_2 + q3 * ekb_3);
        * 
        * return setpoint_;
        * \endcode
        */

        double q1 = koev_peredach_ * (1 + const_difer_ / step_kvant_); /// q1 - Параметр регулятора
        double q2 = -koev_peredach_ * (1 + 2 * const_difer_ / step_kvant_ - step_kvant_ / const_int_); /// q2 - Параметр регулятора
        double q3 = koev_peredach_ * const_difer_ / step_kvant_; /// q3 - Параметр регулятора
        setpoint_ += (q1 * ekb_1 + q2 * ekb_2 + q3 * ekb_3);

        return setpoint_;
    }

public:

    Regulator(double T, double T0, double TD, double K) :
        const_int_(T),step_kvant_(T0), const_difer_(TD),koev_peredach_(K)
    { }

    void pid_calculate_write(double need, double start){
    /**
    * \brief Метод моделирования ПИД-регулятора
    *
    * В данном методе мы моделируем ПИД-регулятор и записываем результаты в файл results.txt
    * \param need Желаемое значение
    * \param start Стартовое значение y
    *
    * Код:
    * \code
    * std::ofstream fout("results.txt");
    * 
    * if (fout){
    *     double ekb_1 = 0;
    *     double ekb_2 = 0;
    *     double ekb_3 = 0;
    *     double y = start;
    *     double u = 0;
    * 
    *     LinearModelPID linear(0.333, 0.667, 1);
    * 
    *     fout << "Линейная модель: " << std::endl;
    * 
    *     for (int i = 0; i < 50; ++i){
    * 
    *         ekb_1 = need - y;
    *         u = calc__uk(ekb_1, ekb_2, ekb_3);
    *         y = linear.calculate_pid_model(start, u);
    *         fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;
    * 
    *         ekb_3 = ekb_2;
    *         ekb_2 = ekb_1;
    *     }
    * 
    *     ekb_2 = 0;
    *     ekb_3 = 0;
    * 
    *     y = start;
    *     setpoint_ = 0;
    * 
    *     fout << "Нелинейная модель: " << std::endl;
    * 
    *     NonlinearModelPID nonLinear(1, 0.0033, 0.525, 0.525, 1);
    *     for (int i = 0; i < 50; ++i){
    *         ekb_1 = need - y;
    *         u = calc__uk(ekb_1, ekb_2, ekb_3);
    *         y = nonLinear.calculate_pid_model(start, u);
    *         fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;
    * 
    *         ekb_3 = ekb_2;
    *         ekb_2 = ekb_1;
    *     }
    * }
    * else{
    *     std::cout << "Не удалось открыть файл для записи результатов." << std::endl;
    * }
    * \endcode
    */

    std::ofstream fout("results.txt");

    if (fout){
        double ekb_1;
        double ekb_2 = 0;
        double ekb_3 = 0;
        double y = start;
        double u;

        LinearModelPID linear(0.333, 0.667, 1);

        fout << "Линейная модель: " << std::endl;

        for (int i = 0; i < 50; ++i){
            ekb_1 = need - y;

            u = calc__uk(ekb_1, ekb_2, ekb_3);
            y = linear.calculate_pid_model(start, u);

            fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;

            ekb_3 = ekb_2;
            ekb_2 = ekb_1;
        }

        ekb_2 = 0;
        ekb_3 = 0;
        y = start;
        setpoint_ = 0;

        fout << "Нелинейная модель: " << std::endl;

        NonlinearModelPID nonLinear(1, 0.0033, 0.525, 0.525, 1);

        for (int i = 0; i < 50; ++i){
            ekb_1 = need - y;

            u = calc__uk(ekb_1, ekb_2, ekb_3);
            y = nonLinear.calculate_pid_model(start, u);

            fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;
            
            ekb_3 = ekb_2;
            ekb_2 = ekb_1;
        }
    }
    else{
            std::cout << "Не удалось открыть файл для записи результатов." << std::endl;
        }
    }
};

int main(){
    /**
    * \brief Главная функция main
    *
    * Создаём объект класса Regulator и вызываем метод для рассчёта и записи результатов в файл
    *
    * Код:
    * \code
    * setlocale(0, "");
    * Regulator object(10,10,50,0.1);
    * object.pid_calculate_write(5, 2);
    * std::cout << "Данные были сохранены в файл results.txt" << std::endl;
    * return 0;
    * \endcode
    */
    setlocale(0, "");

    Regulator object(10, 10, 40, 0.1);

    object.pid_calculate_write(5, 2);

    std::cout << "Данные были сохранены в файл results.txt" << std::endl;

    return 0;
}