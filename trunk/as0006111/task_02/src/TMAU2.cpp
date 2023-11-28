#include <memory>
#include<iostream>
#include<cmath>
using namespace std;

/**
* \mainpage
* \brief Лабораторная работа №2: "ПИД-регуляторы"
* \author Линкевич П.С. АС-61
*/

/**
* \class Model
* \brief Класс, который необходим классам, рассчитывающим линейную и нелинейную модель.
*
* Класс, который предоставляет виртуальную функцию уравнения expression
* и от которого наследуются классы Linear и Non_Linear
*/
class Model
{
public:
    virtual double expression(double heat, double y) = 0;
    virtual ~Model() = default;
};

/**
* \class Linear
* \brief Класс, который служит для реализации линейной модели
*
* Дочерний класс от Model, который реализует линейную модель через  функцию expression
*/
class Linear : public Model
{
private:
double a; ///< Коэффициент
double b; ///< Коэффициент
public:
    Linear(double a, double b) : a(a), b(b) {}

    /**
    * Метод для рассчёта линейной модели
    *
    * Код:
    * \code
    *  y = a * y + b * heat;
    * return y;
    * \endcode
    */
    double expression(double heat, double y) override
    {
        y = a * y + b * heat; ///< Получаемая температура
        return y;
    }

    ~Linear() override = default;
};

/**
* \class Non_Linear
* \brief Класс, который служит для реализации нелинейной модели
*
* Дочерний класс от Model, который реализует нелинейную модель через функцию expression
*/
class Non_Linear : public Model
{
private:
    double a; ///< Коэффициент
    double b; ///< Коэффициент
    double c; ///< Коэффициент
    double d; ///< Коэффициент
    double y0 = 0; ///< Предыдущая температура 
    double heat0 = 0; ///< Предыдущее тепло
public:
    Non_Linear(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    /**
   *Метод для рассчёта нелинейной модели
   *
   * Код:
   * \code
   * auto y1 = a * y - b * pow(y0, 2) + c * heat + d * sin(heat0);
   * y0 = y;
   * heat0 = heat;
   * return y1;
   * \endcode
   */
    double expression(double heat, double y) override
    {
        auto y1 = a * y - b * pow(y0, 2) + c * heat + d * sin(heat0);
        y0 = y;
        heat0 = heat;
        return y1; ///< Получаемая температура
    }

    ~Non_Linear() override = default;
};

/**
* \class Controller
* \brief Класс регулятора
*
* Отдельный класс, в котором мы моделируем регулятор
*/
class Controller
{
private:
    double heat = 0;
    double K; 
    double T; 
    double TD; 
    double T0;
public:
    Controller(double K, double T0, double TD, double T) : K(K), T0(T0), TD(TD), T(T) {}

    double Heat(double e, double e0 = 0, double e1 = 0)
    {
        /**
        * \brief Метод для рассчёта u
        *
        * Метод рассчёта текущего значения управляющего воздействия на объект управления
        *
        * Код:
        * \code
        * double q_0, q_1, q_2;
        * q_0 = K * (1.0 + TD / T0);
        * q_1 = -K * (1 + 2.0 * TD / T0 - T0 / T);
        * q_2 = K * TD / T0;
        * heat += q_0 * e + q_1 * e0 + q_2 * e1;
        * return heat;
        * \endcode
        */
        auto q_0 = K * (1.0 + TD / T0); /// q_0 - Параметр регулятора
        auto q_1 = -K * (1 + 2.0 * TD / T0 - T0 / T); //// q_1 - Параметр регулятора
        auto q_2 = K * TD / T0; /// q_2 - Параметр регулятора
        heat += q_0 * e + q_1 * e0 + q_2 * e1; 
        return heat;
    }
};

void PID_System(const double w, Controller* ins, Model* m, double y)
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
       * double e; 
       *double e0; 
       *double e1; 
       *double u;
       *e = 0.0,
       *e0 = 0.0,
       *e1 = 0.0;
       *u = 0;
       *for (int k = 0; k < 300; k++)
       *{
       *    cout << e << "\t\t" << y << "\t\t" << u << endl;
       *    e = w - y;
       *    u = ins->Heat(e, e0, e1);
       *    y = m->expression(u, y);
       *    e1 = e0;
       *    e0 = e;
       *}
       * \endcode
       */
    double e; 
    double e0; 
    double e1; 
    double u;
    e = 0.0;
    e0 = 0.0;
    e1 = 0.0;
    u = 0;
    for (int k = 0; k < 300; k++)
    {
        cout << e << "\t\t" << y << "\t\t" << u << endl;
        e = w - y;
        u = ins->Heat(e, e0, e1);
        y = m->expression(u, y);
        e1 = e0;
        e0 = e;
    }
}

int main()
{
    /**
   * \brief Главная функция main
   *
   * Код:
   * \code
   *  setlocale(LC_ALL, "Russian");
   *cout << " Линейная модель:\nE\t\tY\t\tU\n";
   *cout << "----------------------------------------------------" << endl;
   *auto m = make_unique<Linear>(0.35, 0.567);
   *auto r = make_unique<Controller>(0.1, 20, 40, 10);
   *PID_System(5, r.get(), m.get(), 1);
   *cout << "\n\n\n Нелинейная модель:\nE\t\tY\t\tU\n";
   *cout << "-----------------------------------------------------" << endl;
   *auto nl = make_unique<Non_Linear>(1, 0.0025, 0.614, 0.777);
   *auto nlr = make_unique<Controller>(0.1, 20, 40, 10);
   *PID_System(5, nlr.get(), nl.get(), 1);
   * return 0;
   * \endcode
   */
    setlocale(LC_ALL, "Russian");

    cout << " Линейная модель:\nE\t\tY\t\tU\n";
    cout << "----------------------------------------------------" << endl;

    auto m = make_unique<Linear>(0.35, 0.567);
    auto r = make_unique<Controller>(0.1, 20, 40, 10);
    PID_System(5, r.get(), m.get(), 1);

    cout << "\n\n\n Нелинейная модель:\nE\t\tY\t\tU\n";
    cout << "-----------------------------------------------------" << endl;

    auto nl = make_unique<Non_Linear>(1, 0.0025, 0.614, 0.777);
    auto nlr = make_unique<Controller>(0.1, 20, 40, 10);
    PID_System(5, nlr.get(), nl.get(), 1);
    return 0;
}
