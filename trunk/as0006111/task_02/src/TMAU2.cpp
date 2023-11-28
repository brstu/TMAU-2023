#include<iostream>
#include<math.h>
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
    virtual float expression(double heat, double y) = 0;
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
    float a, b;///< Коэффициенты
public:
    Linear(const float a, const float b)
    {
        this->a = a;
        this->b = b;
    }

    /**
    * Метод для рассчёта линейной модели
    *
    * Код:
    * \code
    *  y = a * y + b * heat;
    * return y;
    * \endcode
    */
    float expression(double heat, double y) override
    {
        y = a * y + b * heat; ///< Получаемая температура
        return y;
    }
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
    float a, b, c, d; ///< Коэффициенты
    double y0 = 0; ///< Предыдущая температура 
    double heat0 = 0; ///< Предыдущее тепло
public:
    Non_Linear(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    /**
   *Метод для рассчёта нелинейной модели
   *
   * Код:
   * \code
   * y1 = a * y - b * pow(y0, 2) + c * heat + d * sin(heat0);
   * y0 = y;
   * heat0 = heat;
   * return y1;
   * \endcode
   */
    float expression(double heat, double y) override
    {
        double y1;
        y1 = a * y - b * pow(y0, 2) + c * heat + d * sin(heat0);
        y0 = y;
        heat0 = heat;
        return y1; ///< Получаемая температура
    }
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
    double K, T, TD, T0;
public:
    Controller(const double K, const double T0, const double TD, const double T)
    {
        this->K = K; ///< Коэффициент передачи
        this->T0 = T0; ///< Шаг для квантования
        this->TD = TD; ///< Постоянная дифференцирования
        this->T = T; //< Постоянная интегрирования
    }

    double Heat(const double e, const double e0 = 0, const double e1 = 0)
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
        double q_0, q_1, q_2;
        q_0 = K * (1.0 + TD / T0); /// q_0 - Параметр регулятора
        q_1 = -K * (1 + 2.0 * TD / T0 - T0 / T); /// q_1 - Параметр регулятора
        q_2 = K * TD / T0; /// q_2 - Параметр регулятора
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
        * double e, e0, e1, u;
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
    double e, e0, e1, u;
    e = 0.0,
    e0 = 0.0,
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
    *Linear* m = new Linear(0.35, 0.567);
    *Controller* r = new Controller(0.1, 20, 40, 10);
    *PID_System(5, r, m, 1);
    *cout << "\n\n\n Нелинейная модель:\nE\t\tY\t\tU\n";
    *cout << "-----------------------------------------------------" << endl;
    *Non_Linear* nl = new Non_Linear(1, 0.0025, 0.614, 0.777);
    *Controller* nlr = new Controller(0.1, 20, 40, 10);
    *PID_System(5, nlr, nl, 1);
    * return 0;
    * \endcode
    */
    setlocale(LC_ALL, "Russian");

    cout << " Линейная модель:\nE\t\tY\t\tU\n";
    cout << "----------------------------------------------------" << endl;

    Linear* m = new Linear(0.35, 0.567);
    Controller* r = new Controller(0.1, 20, 40, 10);
    PID_System(5, r, m, 1);

    cout << "\n\n\n Нелинейная модель:\nE\t\tY\t\tU\n";
    cout << "-----------------------------------------------------" << endl;

    Non_Linear* nl = new Non_Linear(1, 0.0025, 0.614, 0.777);
    Controller* nlr = new Controller(0.1, 20, 40, 10);
    PID_System(5, nlr, nl, 1);
    return 0;
}