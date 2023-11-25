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
    * \details абстрактная функция предназначенная для переопределения в дочерних классах
    */
    virtual float equation(float y_t, float u_t) = 0;
    virtual ~Models() = default;
};






/**
* \class NonLinMod
* \brief Класс, представляющий нелинейную модель контролируемого объекта
* \details Дочерний класс, служещий для расширения класса Models
*/
class NonLinMod : public Models
{
private:
    
    float Y_t0 = 0; ///< Y_t0 - предыдущее(начальное) значение температуры
    float Y_t1; ///< Y_t1 - текущее значение температуры на выходе
    float U_t0 = 0; ///< U_t0 - переменная для предыдущего значения тепла
    float M; ///< M, A, K, S - коэффициенты
    float A;
    float K;
    float S;

public:
    /**
   * \details конструктор NonLinMod
   */
    NonLinMod(float m, float a, float k, float s, float y_t1) : Y_t1(y_t1), M(m), A(a), K(k), S(s)
    {

    }
    /**
    * \details функция которая вычисляет температуру по нелинейной модели
    */
    float equation(float y_T, float u_T) override
    {

        Y_t1 = M * y_T - A * static_cast<float>(pow(Y_t0, 2)) + K * u_T + S * sin(U_t0);
        Y_t0 = y_T;
        U_t0 = u_T;
        return Y_t1;

    }

    ~NonLinMod() override = default;
};







/**
* \class LinMod
* \brief Класс, представляющий линейную модель контролируемого объекта
* \details Дочерний класс, который расширяет класс Models
*/
class LinMod : public Models
{
    private:
        
        float Y_t1;
        float A;
        float B;

    public:
        /**
        * \details конструктор для LinMod
        * \param A, B - коэффициенты
        * \param Y_t1 - температура на выходе
        */
        LinMod(float w, float e, float y_t1) : Y_t1(y_t1), A(w), B(e)
        {
        }

        /**
        * \details функция для вычисления температуры по линейной модели
        */
        float equation(float y_T, float u_T) override
        {
            Y_t1 = A * y_T + B * u_T;
            return Y_t1;
        }

        ~LinMod() override = default;
};






/**
* \class Regulator
* \brief Класс который реализует регулятор
*/
class Regulator
{
private:
    
    float u = 0;
    float _T_;
    float _T0_;
    float _TD_;
    float _K_;

public:
    /**
    * \details конструктор для Regulator
    * \param _K_,_T0_,_TD_,_T_ : коэффициент передачи, шаг, постоянная диференцирования, постоянная интегрирования
    */
    Regulator(float T, float T0, float TD, float K)
        : _T_(T),  _T0_(T0),  _TD_(TD),  _K_(K)
    {
    }
    /**
    * \details функция для подсчёта управляющей переменной
    * \param mt, mt1, mt2 - это значения ошибок: текущей, прошлой, позапрошлой
    */
    float temperature(float mt, float mt1, float mt2) {

        float p0 = _K_ * (1 + _TD_ / _T0_);
        float p1 = -_K_ * (1 + 2 * _TD_ / _T0_ - _T0_ / _T_);
        float p2 = _K_ * _TD_ / _T0_;
        u += p0 * mt + p1 * mt1 + p2 * mt2;
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

        float y = y0;
        float mt1 = 0;
        float mt2 = 0;
        
        for (int i = 0; i < 100; i++) {

            float u;
            float e;
            
            e = w - y;
            u = reg.temperature(e, mt1, mt2);
            y = md.equation(y0, u);

            fout << "E=" << e << " Y=" << y << " U=" << u << endl;
            mt2 = mt1;
            mt1 = e;
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
        Regulator reglin(10, 10, 50, 0.1f);
        PiDregulator(5, 2, reglin, l);
         fout << "Нелинейная модель:" << endl;
        NonLinMod nl(1.0f, 0.0043f, 0.535f, 0.535f, 1.0f);
         Regulator regnlin(10, 10, 50, 0.1f);
        PiDregulator(6, 3, regnlin, nl);
    }
    cout << "Данные были сохранены в файл result.txt" << endl;
     return 0;
}
