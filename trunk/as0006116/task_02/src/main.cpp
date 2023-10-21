#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Седко Максим Викторович. АС-61
*/

/**
* \class AbstractModel
* \brief Класс, который рассчитывает значения моделей
*/
class ParentModel
{
public:
    virtual ~ParentModel() = default;

    /**
    * \brief Виртуальная функция, которая ассчитывает значения модели.
    */
    virtual double simulate(double y, double warm) = 0;
};
/**
* \class LinearModel
* \brief Класс, который наследуется от класса AbstractModel и служит для реализации линейной модели через переопределение функции simulate
*/
class LinearModel : public ParentModel
{
private:
    double k_a;   
    double k_b;    
    double next_y; 
public:
    LinearModel(double a, double b, double yNext) :
        k_a(a),
        k_b(b),
        next_y(yNext)
    { }

    /**
    *\brief Переопределённый метод, который рассчитывает значения линейной модели
    *
    * Код:
    * \code
    * next_y = k_a * y + k_b * warm;
    * return next_y;
    * \endcode
    */
    double simulate(double y, double warm) override
    {
        next_y = k_a * y + k_b * warm;
        return next_y;
    }
};
/**
* \class NonLinearModel
* \brief Класс, который наследуется от класса AbstractModel и служит для реализации нелинейной модели через переопределение функции simulate
*/
class NonLinearModel : public ParentModel
{
private:
    double k_a;       
    double k_b;   
    double k_c;        
    double k_d;        
    double prev_y = 0; 
    double next_y;     
    double prev_w = 0; 

public:
    NonLinearModel(double a, double b, double c, double d, double yNext) :
        k_a(a),
        k_b(b),
        k_c(c),
        k_d(d),
        next_y(yNext)
    { }

    /**
    *\brief Переопределённый метод, который рассчитывает значения нелинейной модели
    *
    * Код:
    * \code
    * next_y = k_a * y - k_b * pow(prev_y, 2) + k_c * warm + k_d * sin(prev_w);
    * prev_y = next_y;
    * prev_w = warm;
    * return next_y;
    * \endcode
    */
    double simulate(double y, double warm) override
    {
        next_y = k_a * y - k_b * pow(prev_y, 2) + k_c * warm + k_d * sin(prev_w);
        prev_y = y;
        prev_w = warm;
        return next_y;
    }
};
/**
* \class RegObject
* \brief Класс, который реализует вычисление параметров моделей и вывод результатов в файл
*/
class RegObject
{
private:
    double t;      
    double t0;     
    double td;     
    double k_k;   
    double value = 0; 

    double getValue(double koef1, double koef2, double koef3)
    {
        /**
        * \brief Метод для рассчёта текущего значения управляющего воздействия на объект управления
        *
        * Код:
        * \code
        * double q0 = K_ * (1 + TD_ / T0_);
        * double q1 = -K_ * (1 + 2 * TD_ / T0_ - T0_ / T_);
        * double q2 = K_ * TD_ / T0_;
        * value += q0 * koef1 + q1 * koef2 + q2 * koef3;
        * return value;
        * \endcode
        */
        value += (k_k * (1 + td / t0)) * koef1 + (-k_k * (1 + 2 * td / t0 - t0 / t)) * koef2 + (k_k * td / t0) * koef3;
        return value;
    }
public:
    RegObject(double T, double T0, double TD, double K) :t(T),t0(T0),td(TD),k_k(K) { }

    void writeModelsInFile(double n, double begin)
    {
        /**
        * \brief Метод, в котором моделируется ПИД-регулятор и записываются результаты в файл results.txt
        *
        * Код:
        * \code
        * ofstream fout("results.txt");
        * 
        * if (fout)
        * {
        *     double koef1 = 0;
        *     double koef2 = 0;
        *     double koef3 = 0;
        *     double y = begin;
        *     double u = 0;
        * 
        *     LinearModel linear(1, 2, 3);
        *     fout << "Линейная модель: " << endl;
        *     for (int i = 0; i < 50; ++i)
        *     {
        *         koef1 = n - y;
        *         u = getValue(koef1, koef2, koef3);
        *         y = linear.simulate(begin, u);
        *         fout << "E = " << koef1 << " Y = " << y << " U = " << u << endl;
        *         koef3 = koef2;
        *         koef2 = koef1;
        *     }
        * 
        *     koef2 = 0;
        *     koef3 = 0;
        *     y = begin;
        *     value = 0;
        * 
        *     fout << "Нелинейная модель: " << endl;
        *     NonLinearModel nonLinear(3, 0.01, 1.5, 1.5, 3);
        *     for (int i = 0; i < 50; ++i)
        *     {
        *         koef1 = n - y;
        *         u = getValue(koef1, koef2, koef3);
        *         y = nonLinear.simulate(begin, u);
        *         fout << "E = " << koef1 << " Y = " << y << " U = " << u << endl;
        *         koef3 = koef2;
        *         koef2 = koef1;
        *     }
        * cout << "Файл \"results.txt\" успешно создан" << endl;
        * }
        * else
        * {
        *     cout << "Не удалось открыть файл \"result.txt\"" << endl;
        * }
        * \endcode
        */
        ofstream fout("results.txt");

        if (fout)
        {
            double koef1;
            double koef2 = 0;
            double koef3 = 0;
            double y = begin;
            double u;

            LinearModel linear(1, 2, 3);
            fout << "Линейная модель: " << endl;
            for (int i = 0; i < 50; ++i)
            {
                koef1 = n - y;
                u = getValue(koef1, koef2, koef3);
                y = linear.simulate(begin, u);
                fout << "E = " << koef1 << " Y = " << y << " U = " << u << endl;
                koef3 = koef2;
                koef2 = koef1;
            }

            koef2 = 0;
            koef3 = 0;
            y = begin;
            value = 0;

            fout << "Нелинейная модель: " << endl;
            NonLinearModel nonLinear(3, 0.01, 1.5, 1.5, 3);
            for (int i = 0; i < 50; ++i)
            {
                koef1 = n - y;
                u = getValue(koef1, koef2, koef3);
                y = nonLinear.simulate(begin, u);
                fout << "E = " << koef1 << " Y = " << y << " U = " << u << endl;
                koef3 = koef2;
                koef2 = koef1;
            }
            cout << "Файл \"results.txt\" успешно создан" << endl;
        }
        else
        {
            cout << "Не удалось открыть файл \"result.txt\"" << endl;
        }
    }
};

int main()
{
    /**
    * \brief Главная функция, в которой создаётся объект и вызывается метод, проводящий рассчёты и выводящий результаты в файл
    *
    * Код:
    * \code
    * setlocale(0, "");
    * RegObject object(10,10,50,0.1);
    * object.writeModelsInFile(5, 2);
    * return 0;
    * \endcode
    */
    setlocale(0, "");
    RegObject object(30, 30, 120, 0.3);
    object.writeModelsInFile(5, 2);
    return 0;
}
