#include <iostream>
#include <cmath>
#include <fstream>
/**
 * \mainpage
 * \brief Лабораторная работа 2. ПИД-регуляторы
 * \author Рыжко Сергей Игоревич. АС-61
 */

/**
 * \class Model
 * \brief Абстрактный класс, предоставляющий функцию уравнения modelFunc, являющийся основой для других моделей
 */
class Model
{
public:
    virtual ~Model() = default;

    /**
     * \brief Виртуальный метод, переопределяемый в классах реализующих данную модель
     *
     * Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели.
     * \param curTemp Текущая температура в помещении
     * \param warm Входящее тепло
     */
    virtual double modelFunc(double curTemp, double warm) = 0;
};

/**
 * \class Linear
 * \brief Класс представляющий линейную математическую модель
 *
 * Подкласс Model, представляющий линейную модель, переопределяющий абстрактный метод modelFunc
 */
class Linear : public Model
{
    double A;        /// Первый коэф.
    double B;        /// Второй коэф.
    double nextTemp; /// Температура на выходе
public:
    Linear(double a, double b, double nextTemp) : A(a),
                                                  B(b),
                                                  nextTemp(nextTemp)
    {
    }

    /**
     * Переопределённый метод для рассчёта линейной математической модели
     *
     * Код:
     * \code
     * return A * currentTemp + B * warmth;
     * \endcode
     */
    double modelFunc(double currentTemp, double warmth) override
    {
        nextTemp = A * currentTemp + B * warmth;
        return nextTemp;
    }
};

/**
 * \class NonLinear
 * \brief Класс представляющий нелинейную математическую модель
 *
 * Подкласс от Model, представляющий нелинейную модель, переопределяющий метод modelFunc
 */
class NonLinear : public Model
{
    double A;              /// Первый коэф.
    double B;              /// Второй коэф.
    double C;              /// Третий коэф.
    double D;              /// Четвертый коэф.
    double prevTemp = 0;   /// Предыдущая полученная температура
    double nextTemp;       /// Текущая температура
    double prevWarmth = 0; /// Предыдущее полученное тепло

public:
    NonLinear(double a, double b, double c, double d, double nextTemp) : A(a),
                                                                         B(b),
                                                                         C(c),
                                                                         D(d),
                                                                         nextTemp(nextTemp)
    {
    }

    /**
    * Переопределённый метод для рассчёта нелинейной модели
    *
    * Код:
    * \code
        nextTemp = A * yCurrent - B * pow(prevTemp, 2) + C * inputWarm + D * sin(prevWarmth);
        prevTemp = yCurrent;
        prevWarmth = inputWarm;
        return nextTemp;
    * \endcode
    */
    double modelFunc(double yCurrent, double inputWarm) override
    {
        nextTemp = A * yCurrent - B * pow(prevTemp, 2) + C * inputWarm + D * sin(prevWarmth);
        prevTemp = yCurrent;
        prevWarmth = inputWarm;
        return nextTemp;
    }
};

/**
 * \class Regulator
 * \brief Модель ПИД регулятора
 */
class Regulator
{
private:
    double T;      /// Постоянная интегрирования
    double TO;     /// Временной шаг
    double TD;     /// Постоянная дифференцирования
    double K;      /// Коэффициент передачи
    double Uk = 0; /// Значение управляющего воздействия

    /**
     * \brief Метод для рассчёта управляющего воздействия Uk
     *
     * Метод рассчёта текущего значения управляющего воздействия на объект управления
     *
     * Код:
     * \code
     * double q0 = K * (1 + TD / TO);
     * double q1 = -K * (1 + 2 * TD / TO - TO / T);
     * double q2 = K * TD / TO;
     * Uk += q0 * ek + q1 * ek1 + q2 * ek2;
     * return Uk;
     * \endcode
     */

    double calculateControlSignal(double ek, double ek1, double ek2)
    {
        double q0 = K * (1 + TD / TO);
        double q1 = -K * (1 + 2 * TD / TO - TO / T);
        double q2 = K * TD / TO;
        Uk += q0 * ek + q1 * ek1 + q2 * ek2;
        return Uk;
    }

public:
    Regulator(double T, double T0, double TD, double K) : T(T),
                                                          TO(T0),
                                                          TD(TD),
                                                          K(K)
    {
    }

    /**
* \brief Метод эмулируюший закон регулирования ПИД-регулятора
*
* В методе используем закон регулирования и записываем результаты в файл
* \param want Желаемое значение
* \param initial Стартовое значение
*
* Код:
* \code
* std::ofstream fout("results.txt");
*
*       if (fout)
*       {
*           double ek;
*           double ek1 = 0;
*           double ek2 = 0;
*           double y = initial;
*           double u;
*           Linear linear(0.333, 0.667, 1);
*           fout << "Линейная модель: " << std::endl;
*           for (int i = 0; i < 50; ++i)
*           {
*               ek = want - y;
*               u = calculateControlSignal(ek, ek1, ek2);
*               y = linear.modelFunc(initial, u);
*               fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
*               ek2 = ek1;
*               ek1 = ek;
*           }
*           ek1 = 0;
*           ek2 = 0;
*           y = initial;
*           Uk = 0;
*           fout << "Нелинейная модель: " << std::endl;
*           NonLinear nonLinear(1, 0.0033, 0.525, 0.525, 1);
*           for (int i = 0; i < 50; i++)
*           {
*               ek = want - y;
*               u = calculateControlSignal(ek, ek1, ek2);
*               y = nonLinear.modelFunc(initial, u);
*               fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
*               ek2 = ek1;
*               ek1 = ek;
*           }
*           std::cout << "Успешно сохранено в results.txt" << std::endl;
*       }
*       else
*       {
*           std::cout << "Ошибка при сохранении данных в файловую систему" << std::endl;
*       }

* \endcode
*/

    void Regulate(double want, double initial)
    {
        std::ofstream fout("results.txt");

        if (fout)
        {
            double ek;
            double ek1 = 0;
            double ek2 = 0;
            double y = initial;
            double u;

            Linear linear(0.2, 0.5, 1);
            fout << "Линейная модель: " << std::endl;
            for (int i = 0; i < 50; ++i)
            {
                ek = want - y;
                u = calculateControlSignal(ek, ek1, ek2);
                y = linear.modelFunc(initial, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }

            ek1 = 0;
            ek2 = 0;
            y = initial;
            Uk = 0;

            fout << "Нелинейная модель: " << std::endl;
            NonLinear nonLinear(1, 0.5, 0.3, 0.5, 1);
            for (int i = 0; i < 50; i++)
            {
                ek = want - y;
                u = calculateControlSignal(ek, ek1, ek2);
                y = nonLinear.modelFunc(initial, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }
            std::cout << "Успешно сохранено в results.txt" << std::endl;
        }
        else
        {
            std::cout << "Ошибка при сохранении данных в файловую систему" << std::endl;
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
     * Regulator object(5, 5, 40, 0.1);
     * object.Regulate(4, 2);
     * return 0;
     * \endcode
     */
    Regulator object(10, 10, 40, 0.1);
    object.Regulate(4, 2);
    return 0;
}
