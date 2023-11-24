#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;




/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Павлючик Адександр Сергеевич. АС-61
*/

/**
* \class AbstMod
* \brief Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
*
* Абстрактный класс, который предоставляет виртуальную функцию уравнения calculMod
* и от которого наследуются классы LinearMod и NonLinearMod
*/




class AbstMod
{
public:
    virtual ~AbstMod() = default;



    /**
    * \brief Виртуальная функция, переопределенная в дочерних классах LinearMod и NonLinearMod
    *
    * Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели.
    * \param yCurrent Температура помещения
    * \param inputWarm Входящее тепло
    */
    virtual double calculMod(double yCurrent, double inputWarm) = 0;
};
/**
* \class LinearMod
* \brief Класс, который служит для реализации линейной модели
*
* Дочерний класс от AbstMod, который реализует линейную модель через переопределённую функцию calculMod
*/




class LinearMod : public AbstMod
{

private:
    double a___;     ///< Коэффициент
    double b___;     ///< Коэффициент
    double yNext_; ///< Получаемая нами температура



public:
    LinearMod(double a, double b, double yNext) :
        a___(a),
        b___(b),
        yNext_(yNext)
    { }

    /**
    * Переопределённый метод для рассчёта линейной модели
    *
    * Код:
    * \code
    * yNext_ = a___ * yCurrent + b___ * inputWarm;
    * return yNext_;
    * \endcode
    */
    double calculMod(double yCurrent, double inputWarm) override
    {
        yNext_ = a___ * yCurrent + b___ * inputWarm;
        return yNext_;
    }
};



/**
* \class NonLinearMod
* \brief Класс, который служит для реализации нелинейной модели
*
* Дочерний класс от AbstMod, который реализует нелинейную модель через переопределённую функцию calculMod
*/



class NonLinearMod : public AbstMod
{


private:
    double a___;         ///< Коэффициент
    double b___;         ///< Коэффициент
    double c___;         ///< Коэффициент
    double d___;         ///< Коэффициент
    double yPrev_ = 0; ///< Предыдущая температура 
    double yNext_;     ///< Получаемая нами температура
    double wPrev_ = 0; ///< Предыдущее тепло

public:
    NonLinearMod(double a, double b, double c, double d, double yNext) :
        a___(a),
        b___(b),
        c___(c),
        d___(d),
        yNext_(yNext)
    { }




    /**
    * Переопределённый метод для рассчёта нелинейной модели
    *
    * Код:
    * \code
    * yNext_ = a___ * yCurrent - b___ * pow(yPrev_, 2) + c___ * inputWarm + d___ * sin(wPrev_);
    * yPrev_ = yNext_;
    * wPrev_ = inputWarm;
    * return yNext_;
    * \endcode
    */



                       
    double calculMod(double yCurrent, double inputWarm) override
    {
        yNext_ = a___ * yCurrent - b___ * pow(yPrev_, 2) + c___ * inputWarm + d___ * sin(wPrev_);
        yPrev_ = yCurrent;
        wPrev_ = inputWarm;
        return yNext_;
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
    double t_;      ///< Постоянная интегрирования
    double t0_;     ///< Шаг для квантования
    double td___;     ///< Постоянная дифференцирования
    double k_;      ///< Коэффициент передачи
    double uk_ = 0; ///< Текущее значение управляющего воздействия



                         

    double calcul(double ek, double ek1, double ek2)
    {
        /**
        * \brief Метод для рассчёта uk_
        *
        * Метод рассчёта текущего значения управляющего воздействия на объект управления
        *
        * Код:
        * \code
        * double q0 = K_ * (1 + Td___ / T0_);
        * double q1 = -K_ * (1 + 2 * Td___ / T0_ - T0_ / T_);
        * double q2 = K_ * Td___ / T0_;
        * uk_ += q0 * ek + q1 * ek1 + q2 * ek2;
        * return uk_;
        * \endcode
        */




        double q0 = k_ * (1 + td___ / t0_); /// q0 - Параметр регулятора
        double q1 = -k_ * (1 + 2 * td___ / t0_ - t0_ / t_); /// q1 - Параметр регулятора
        double q2 = k_ * td___ / t0_; /// q2 - Параметр регулятора
        uk_ += q0 * ek + q1 * ek1 + q2 * ek2;
        return uk_;
    }




public:
    Regulator(double T, double T0, double TD, double K) :
        t_(T),
        t0_(T0),
        td___(TD),
        k_(K)
    { }




    void PIDRegulatorCalculateAndWrite(double need, double start)
    {
        /**
        * \brief Метод моделирования ПИД-регулятора
        *
        * В данном методе мы моделируем ПИД-регулятор и записываем результаты в файл results.txt
        * \param need Желаемое значение
        * \param start Стартовое значение y
        *
        * Код:
        * \code
        * ofstream fout("results.txt");
        * 
        * if (fout)
        * {
        *     double ek = 0;
        *     double ek1 = 0;
        *     double ek2 = 0;
        *     double y = start;
        *     double u = 0;
        * 
        *     LinearMod linear(0.333, 0.667, 1);
        *     fout << "Линейная модель: " << endl;
        *     for (int i = 0; i < 50; ++i)
        *     {
        *         ek = need - y;
        *         u = calcul(ek, ek1, ek2);
        *         y = linear.calculMod(start, u);
        *         fout << "E=" << ek << " Y=" << y << " U=" << u << endl;
        *         ek2 = ek1;
        *         ek1 = ek;
        *     }
        * 
        *
        *
        *     ek1 = 0;
        *     ek2 = 0;
        *     y = start;
        *     uk_ = 0;
        * 
        *     fout << "Нелинейная модель: " << endl;
        *     NonLinearMod nonLinear(1, 0.0033, 0.525, 0.525, 1);
        *     for (int i = 0; i < 50; ++i)
        *     {
        *         ek = need - y;
        *         u = calcul(ek, ek1, ek2);
        *         y = nonLinear.calculMod(start, u);
        *         fout << "E=" << ek << " Y=" << y << " U=" << u << endl;
        *         ek2 = ek1;
        *         ek1 = ek;
        *     }
        * }
        * else
        * {
        *     cout << "Не удалось открыть файл для записи результатов." << endl;
        * }
        * \endcode
        */




        ofstream fout("results.txt");

        if (fout)
        {
            double ek;
            double ek1 = 0;
            double ek2 = 0;
            double y = start;
            double u;





            LinearMod linear(0.333, 0.667, 1);
            fout << "Линейная модель: " << endl;
            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;
                u = calcul(ek, ek1, ek2);
                y = linear.calculMod(start, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << endl;
                ek2 = ek1;
                ek1 = ek;
            }





            ek1 = 0;
            ek2 = 0;
            y = start;
            uk_ = 0;

            fout << "Нелинейная модель: " << endl;
            NonLinearMod nonLinear(1, 0.0033, 0.525, 0.525, 1);
            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;
                u = calcul(ek, ek1, ek2);
                y = nonLinear.calculMod(start, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << endl;
                ek2 = ek1;
                ek1 = ek;
            }
        }


        else
        {
            cout << "Не удалось открыть файл для записи результатов." << endl;
        }
    }
};




int main()
{
    /**
    * \brief Главная функция main
    *
    * Создаём объект класса Regulator и вызываем метод для рассчёта и записи результатов в файл
    *
    * Код:
    * \code
    * setlocale(0, "");
    * Regulator object(10,10,50,0.1);
    * object.PIDRegulatorCalculateAndWrite(5, 2);
    * cout << "Данные были сохранены в файл results.txt" << endl;
    * return 0;
    * \endcode
    */



    setlocale(0, "");
    Regulator object(10, 10, 40, 0.1);
    object.PIDRegulatorCalculateAndWrite(5, 2);
    cout << "Данные были сохранены в файл results.txt" << endl;
    return 0;
}