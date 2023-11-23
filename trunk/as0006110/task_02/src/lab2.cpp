#include <iostream>
#include <cmath>
#include <fstream>

/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Леонович А.А. АС-61
*/

/**
* \class AbsModPID
* \brief Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
*
* Абстрактный класс, который предоставляет виртуальную функцию уравнения calc_PID
* и от которого наследуются классы Non_line_PID и Line_PID
*/
class AbsModPID
{
public:
    virtual ~AbsModPID() = default;

    /**
    * \brief Виртуальная функция, переопределенная в дочерних классах Non_line_PID и Line_PID
    *
    * Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели.
    * \param current_temperature Температура помещения
    * \param teplo_vhod Входящее тепло
    */
    virtual double calc_PID(double current_temperature, double teplo_vhod) = 0;
};


/**
* \class Non_line_PID
* \brief Класс, который служит для реализации нелинейной модели
*
* Дочерний класс от AbsModPID, который реализует нелинейную модель через переопределённую функцию calc_PID
*/
class Non_line_PID : public AbsModPID
{
private:
    double _a_;         ///< Коэффициент
    double _b_;         ///< Коэффициент
    double _c_;         ///< Коэффициент
    double _d_;         ///< Коэффициент
    double _prevY_ = 0; ///< Предыдущая температура 
    double _nextY_;     ///< Получаемая нами температура
    double _prevW_ = 0; ///< Предыдущее тепло



public:

    Non_line_PID(double a, double b, double c, double d, double yNext) :
        _a_(a), _b_(b), _c_(c), _d_(d), _nextY_(yNext)
    { }

    /**
    * Переопределённый метод для рассчёта нелинейной модели
    *
    * Код:
    * \code
    * _nextY_ = _a_ * current_temperature - _b_ * pow(_prevY_, 2) + _c_ * teplo_vhod + _d_ * sin(_prevW_);
    * _prevY_ = _nextY_;
    * _prevW_ = teplo_vhod;
    * return _nextY_;
    * \endcode
    */

    double calc_PID(double current_temperature, double teplo_vhod) override{
        _nextY_ = _a_ * current_temperature - _b_ * pow(_prevY_, 2) + _c_ * teplo_vhod + _d_ * sin(_prevW_);
        _prevY_ = current_temperature;
        _prevW_ = teplo_vhod;
        return _nextY_;
    }
};


/**
* \class regulator_detka
* \brief Класс регулятора
*
* Отдельный класс, в котором мы моделируем регулятор
*/

/**
* \class Line_PID
* \brief Класс, который служит для реализации линейной модели
*
* Дочерний класс от AbsModPID, который реализует линейную модель через переопределённую функцию calc_PID
*/
class Line_PID : public AbsModPID
{
private:

    double _a_;     ///< Коэффициент
    double _b_;     ///< Коэффициент
    double _nextY_; ///< Получаемая нами температура

public:
    Line_PID(double a, double b, double yNext) :
        _a_(a), _b_(b), _nextY_(yNext)
    { }

    /**
    * Переопределённый метод для рассчёта линейной модели
    *
    * Код:
    * \code
    * _nextY_ = _a_ * current_temperature + _b_ * teplo_vhod;
    * return _nextY_;
    * \endcode
    */

    double calc_PID(double current_temperature, double teplo_vhod) override{
        _nextY_ = _a_ * current_temperature + _b_ * teplo_vhod;
        return _nextY_;
    }
};
class regulator_detka
{
private:

    double _const_int_;      ///< Постоянная интегрирования
    double _stepen_kvantovania_;     ///< Шаг для квантования
    double _const_diferentsivania_;     ///< Постоянная дифференцирования
    double _koevicient_peredachi_;      ///< Коэффициент передачи
    double zadanii_tochki = 0; ///< Текущее значение управляющего воздействия

    double calculation_c_uk(double _ek_b_1_, double _ek_b_2_, double _ek_b_3_){
        /**
        * \brief Метод для рассчёта zadanii_tochki
        *
        * Метод рассчёта текущего значения управляющего воздействия на объект управления
        *
        * Код:
        * \code
        * 
        * double _q1_ = _koevicient_peredachi_ * (1 + _const_diferentsivania_ / _stepen_kvantovania_);
        * double _q2_ = -_koevicient_peredachi_ * (1 + 2 * _const_diferentsivania_ / _stepen_kvantovania_ - _stepen_kvantovania_ / _const_int_);
        * double _q3_ = _koevicient_peredachi_ * _const_diferentsivania_ / _stepen_kvantovania_;
        * zadanii_tochki += (_q1_ * _ek_b_1_ + _q2_ * _ek_b_2_ + _q3_ * _ek_b_3_);
        * 
        * return zadanii_tochki;
        * \endcode
        */

        double _q1_ = _koevicient_peredachi_ * (1 + _const_diferentsivania_ / _stepen_kvantovania_); /// _q1_ - Параметр регулятора
        double _q2_ = -_koevicient_peredachi_ * (1 + 2 * _const_diferentsivania_ / _stepen_kvantovania_ - _stepen_kvantovania_ / _const_int_); /// _q2_ - Параметр регулятора
        double _q3_ = _koevicient_peredachi_ * _const_diferentsivania_ / _stepen_kvantovania_; /// _q3_ - Параметр регулятора
        zadanii_tochki += (_q1_ * _ek_b_1_ + _q2_ * _ek_b_2_ + _q3_ * _ek_b_3_);

        return zadanii_tochki;
    }

public:

    regulator_detka(double T, double T0, double TD, double K) :
        _const_int_(T),_stepen_kvantovania_(T0), _const_diferentsivania_(TD),_koevicient_peredachi_(K)
    { }

    void _pid_calculate_write_(double neobhodima, double nachalo){
    /**
    * \brief Метод моделирования ПИД-регулятора
    *
    * В данном методе мы моделируем ПИД-регулятор и записываем результаты в файл results.txt
    * \param neobhodima Желаемое значение
    * \param nachalo Стартовое значение y
    *
    * Код:
    * \code
    * std::ofstream fout("results.txt");
    * 
    * if (fout){
    *     double _ek_b_1_ = 0;
    *     double _ek_b_2_ = 0;
    *     double _ek_b_3_ = 0;
    *     double y = nachalo;
    *     double u = 0;
    * 
    *     Line_PID linear(0.333, 0.667, 1);
    * 
    *     fout << "Линейная модель: " << std::endl;
    * 
    *     for (int i = 0; i < 50; ++i){
    * 
    *         _ek_b_1_ = neobhodima - y;
    *         u = calculation_c_uk(_ek_b_1_, _ek_b_2_, _ek_b_3_);
    *         y = linear.calc_PID(nachalo, u);
    *         fout << "E=" << _ek_b_1_ << " Y=" << y << " U=" << u << std::endl;
    * 
    *         _ek_b_3_ = _ek_b_2_;
    *         _ek_b_2_ = _ek_b_1_;
    *     }
    * 
    *     _ek_b_2_ = 0;
    *     _ek_b_3_ = 0;
    * 
    *     y = nachalo;
    *     zadanii_tochki = 0;
    * 
    *     fout << "Нелинейная модель: " << std::endl;
    * 
    *     Non_line_PID nonLinear(1, 0.0033, 0.525, 0.525, 1);
    *     for (int i = 0; i < 50; ++i){
    *         _ek_b_1_ = neobhodima - y;
    *         u = calculation_c_uk(_ek_b_1_, _ek_b_2_, _ek_b_3_);
    *         y = nonLinear.calc_PID(nachalo, u);
    *         fout << "E=" << _ek_b_1_ << " Y=" << y << " U=" << u << std::endl;
    * 
    *         _ek_b_3_ = _ek_b_2_;
    *         _ek_b_2_ = _ek_b_1_;
    *     }
    * }
    * else{
    *     std::cout << "Не удалось открыть файл для записи результатов." << std::endl;
    * }
    * \endcode
    */

    std::ofstream fout("results.txt");

    if (fout){
        double _ek_b_1_;
        double _ek_b_2_ = 0;
        double _ek_b_3_ = 0;
        double y = nachalo;
        double u;

        Line_PID linear(0.333, 0.667, 1);

        fout << "Линейная модель: " << std::endl;

        for (int i = 0; i < 50; ++i){
            _ek_b_1_ = neobhodima - y;

            u = calculation_c_uk(_ek_b_1_, _ek_b_2_, _ek_b_3_);
            y = linear.calc_PID(nachalo, u);

            fout << "E=" << _ek_b_1_ << " Y=" << y << " U=" << u << std::endl;

            _ek_b_3_ = _ek_b_2_;
            _ek_b_2_ = _ek_b_1_;
        }

        _ek_b_2_ = 0;
        _ek_b_3_ = 0;
        y = nachalo;
        zadanii_tochki = 0;

        fout << "Нелинейная модель: " << std::endl;

        Non_line_PID nonLinear(1, 0.0033, 0.525, 0.525, 1);

        for (int i = 0; i < 50; ++i){
            _ek_b_1_ = neobhodima - y;

            u = calculation_c_uk(_ek_b_1_, _ek_b_2_, _ek_b_3_);
            y = nonLinear.calc_PID(nachalo, u);

            fout << "E=" << _ek_b_1_ << " Y=" << y << " U=" << u << std::endl;
            
            _ek_b_3_ = _ek_b_2_;
            _ek_b_2_ = _ek_b_1_;
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
    * Создаём объект класса regulator_detka и вызываем метод для рассчёта и записи результатов в файл
    *
    * Код:
    * \code
    * setlocale(0, "");
    * regulator_detka object(10,10,50,0.1);
    * object._pid_calculate_write_(5, 2);
    * std::cout << "Данные сохранены в файл results.txt" << std::endl;
    * return 0;
    * \endcode
    */
    setlocale(0, "");

    regulator_detka object(10, 10, 40, 0.1);

    object._pid_calculate_write_(5, 2);

    std::cout << "Данные сохранены в файл results.txt" << std::endl;

    return 0;
}