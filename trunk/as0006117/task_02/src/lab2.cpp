#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

/**
* \mainpage
* \brief ПИД-регулятор
* \author Ткачук Максим; Группа АС-61
*/
using namespace std;

/**
* \class  Models
* \brief  Абстрактный класс, который будет использоваться для построения линейных и нелинейных моделей
*/
class Models
{
    public:
    /**
    * \details абстрактная функция для переопределения в дочерних классах
    */
    virtual float equation(float y_t, float u_t) = 0;
    virtual ~Models() = default;
};

/**
* \class LinMod
* \brief Класс, представляющий линейную модель контролируемого объекта
* \details Дочерний класс, который расширяет класс Models
*/
class LinMod : public Models
{
    private:
        float A;
        float B;
        float Y_t1;

    public:
        /**
        * \details конструктор для LinMod
        * \param A, B - коэффициенты
        * \param Y_t1 - температура на выходе
        */
        LinMod(float a, float b, float y_t1)
            : A(a), B(b), Y_t1(y_t1)
        {
        }

        /**
        * \details функция для вычисления температуры по линейной модели
        */
        float equation(float y_t, float u_t) override
        {
            Y_t1 = A * y_t + B * u_t;
            return Y_t1;
        }

        ~LinMod() override = default;
};

/**
* \class NonLinMod
* \brief Класс, представляющий нелинейную модель контролируемого объекта
* \details Дочерний класс, который расширяет класс Models
*/
class NonLinMod : public Models
{
private:
    float A; ///< A, B, C, D - коэффициенты
    float B;
    float C;
    float D;
    float Y_t0 = 0; ///< Y_t0 - предыдущее(начальное) значение температуры
    float Y_t1; ///< Yтекущее значение температуры на выходе
    float U_t0 = 0; ///< U_t0 - переменная для предыдущего значения тепла
public:
    /**
   * \details конструктор для NonLinMod
   */
    NonLinMod(float a, float b, float c, float d, float y_t1)
        : A(a), B(b), C(c), D(d), Y_t1(y_t1)
    {
    }
    /**
    * \details функция для вычисления температуры по нелинейной модели
    */
    float equation(float y_t, float u_t) override
    {
        Y_t1 = A * y_t - B * static_cast<float>(pow(Y_t0, 2)) + C * u_t + D * sin(U_t0);
        U_t0 = u_t;
        Y_t0 = y_t;
        return Y_t1;
    }

    ~NonLinMod() override = default;
};

/**
* \class Regulator
* \brief Класс для реализации регулятора
*/
class Regulator
{
private:
    float _T_;
    float _T0_;
    float _TD_;
    float _K_;
    float u = 0;

public:
    /**
    * \details конструктор для Regulator
    * \param _K_,_T0_,_TD_,_T_ слева-направо: коэффициент передачи, шаг, постоянная диференцирования, постоянная интегрирования
    */
    Regulator(float T, float T0, float TD, float K)
        : _T_(T),  _T0_(T0),  _TD_(TD),  _K_(K)
    {
    }
    /**
    * \details функция для подсчёта управляющей переменной
    * \param mt, mt1, mt2 значения текущей, прошлой и позапрошлой ошибок
    */
    float temperature(float mt, float mt1, float mt2) {
        float q0 = _K_ * (1 + _TD_ / _T0_);
         float q1 = -_K_ * (1 + 2 * _TD_ / _T0_ - _T0_ / _T_);
        float q2 = _K_ * _TD_ / _T0_;
        u += q0 * mt + q1 * mt1 + q2 * mt2;
        return u;
    }
};

/**
* \brief Функция, которая моделирует ПИД-регулятор
* \details функция имитирует работу ПИД-регулятора
* \param w желаемое значение
* \param *reg указатель на экземпляр Regulator
* \param *md указатель на экземпляр Models
* \param y0 начальное значение y
*/
void PiDregulator(float w, float y0, Regulator& reg, Models& md) {
    ofstream fout;
    fout.open("D:\\5 семестр\\ТиМАУ\\Lab2\\lab2\\lab2\\result.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        float em1 = 0;
         float em2 = 0;
        float y = y0;
        for (int i = 0; i < 100; i++) {
            float e;
            float u;

            e = w - y;
            u = reg.temperature(e, em1, em2);
             y = md.equation(y0, u);

            fout << "E=" << e << " Y=" << y << " U=" << u << endl;
            em2 = em1;
            em1 = e;
        }
    }
    fout.close();
}

/**
* \brief Функция main, создаём экземпляры всех классов и вызываем функцию PiDregulator
*/
int main() {
    setlocale(0, "");
     ofstream fout;
    fout.open("D:\\5 семестр\\ТиМАУ\\Lab2\\lab2\\lab2\\result.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        fout << "Линейная модель : " << endl;
         LinMod l(0.333f, 0.667f, 1);
        Regulator regl(10, 10, 50, 0.1f);
        PiDregulator(5, 2, regl, l);
         fout << "Нелинейная модель:" << endl;
        NonLinMod nl(1.0f, 0.0043f, 0.535f, 0.535f, 1.0f);
         Regulator regnl(10, 10, 50, 0.1f);
        PiDregulator(6, 3, regnl, nl);
    }
    cout << "Данные были сохранены в файл result.txt" << endl;
     return 0;
}
