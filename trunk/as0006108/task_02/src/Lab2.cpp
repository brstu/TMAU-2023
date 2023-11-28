#include <iostream>
#include <cmath>
#include <fstream>

/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Клунин Тимур. АС-61
*/
/**
* \class AbsModPID
* \brief Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
*
* Абстрактный класс, который предоставляет виртуальную функцию уравнения calcPIDMod
* и от которого наследуются классы LinModPID и NonModPID
*/

class AbsModPID
{
public:
   virtual ~AbsModPID() = default;

   /**
   * \brief Виртуальная функция, переопределенная в дочерних классах LinModPID и NonModPID
   *
   * Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели.
   * \param curTemmmp Температура помещения
   * \param warmInpuutt Входящее тепло
   */
   virtual double calcPIDMod(double curTemmmp, double warmInpuutt) = 0;
};




/**
* \class NonModPID
* \brief Класс, который служит для реализации нелинейной модели
*
* Дочерний класс от AbsModPID, который реализует нелинейную модель через переопределённую функцию calcPIDMod
*/
class NonModPID : public AbsModPID
{
private:
   double a_;   ///< Коэффициент
   double b_;   ///< Коэффициент
   double c__;   ///< Коэффициент
   double d;   ///< Коэффициент
   double prevY___ = 0; ///< Предыдущая температура 
   double nextY___;   ///< Получаемая нами температура
   double prevW__ = 0; ///< Предыдущее тепло
public:

   NonModPID(double a, double b, double c, double d, double yNext) :
   a_(a), b_(b), c__(c), d(d), nextY___(yNext)
   { }


   /**
   * Переопределённый метод для рассчёта нелинейной модели
   *
   * Код:
   * \code
   * nextY___ = a_ * curTemmmp - b_ * pow(prevY___, 2) + c__ * warmInpuutt + d * sin(prevW__);
   * prevY___ = nextY___;
   * prevW__ = warmInpuutt;
   * return nextY___;
   * \endcode
   */

   double calcPIDMod(double curTemmmp, double warmInpuutt) override{
   nextY___ = a_ * curTemmmp - b_ * pow(prevY___, 2) + c__ * warmInpuutt + d * sin(prevW__);
   prevY___ = curTemmmp;
   prevW__ = warmInpuutt;
   return nextY___;
   }
};


/**
* \class LinModPID
* \brief Класс, который служит для реализации линейной модели
*
* Дочерний класс от AbsModPID, который реализует линейную модель через переопределённую функцию calcPIDMod
*/
class LinModPID : public AbsModPID
{
private:

   double a_;   ///< Коэффициент
   double b_;   ///< Коэффициент
   double nextY___; ///< Получаемая нами температура

public:
   LinModPID(double a, double b, double yNext) :
   a_(a), b_(b), nextY___(yNext)
   { }

   /**
   * Переопределённый метод для рассчёта линейной модели
   *
   * Код:
   * \code
   * nextY___ = a_ * curTemmmp + b_ * warmInpuutt;
   * return nextY___;
   * \endcode
   */

   double calcPIDMod(double curTemmmp, double warmInpuutt) override{
   nextY___ = a_ * curTemmmp + b_ * warmInpuutt;
   return nextY___;
   }
};

/**
* \class RegulPID
* \brief Класс регулятора
*
* Отдельный класс, в котором мы моделируем регулятор
*/

class RegulPID
{
private:

   double const_int_;   ///< Постоянная интегрирования
   double step_kvant_;   ///< Шаг для квантования
   double const_difer_;   ///< Постоянная дифференцирования
   double koev_peredach_;   ///< Коэффициент передачи
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

   RegulPID(double T, double T0, double TD, double K) :
   const_int_(T),step_kvant_(T0), const_difer_(TD),koev_peredach_(K)
   { }

   void PIDCalcWrit(double need, double start){
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
   *   double ekb_1 = 0;
   *   double ekb_2 = 0;
   *   double ekb_3 = 0;
   *   double y = start;
   *   double u = 0;
   * 
   *   LinModPID linear(0.333, 0.667, 1);
   * 
   *   fout << "Линейная модель: " << std::endl;
   * 
   *   for (int i = 0; i < 50; ++i){
   * 
   *   ekb_1 = need - y;
   *   u = calc__uk(ekb_1, ekb_2, ekb_3);
   *   y = linear.calcPIDMod(start, u);
   *   fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;
   * 
   *   ekb_3 = ekb_2;
   *   ekb_2 = ekb_1;
   *   }
   * 
   *   ekb_2 = 0;
   *   ekb_3 = 0;
   * 
   *   y = start;
   *   setpoint_ = 0;
   * 
   *   fout << "Нелинейная модель: " << std::endl;
   * 
   *   NonModPID nonLinear(1, 0.0033, 0.525, 0.525, 1);
   *   for (int i = 0; i < 50; ++i){
   *   ekb_1 = need - y;
   *   u = calc__uk(ekb_1, ekb_2, ekb_3);
   *   y = nonLinear.calcPIDMod(start, u);
   *   fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;
   * 
   *   ekb_3 = ekb_2;
   *   ekb_2 = ekb_1;
   *   }
   * }
   * else{
   *   std::cout << "Не удалось открыть файл для записи результатов." << std::endl;
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

   LinModPID linear(0.333, 0.667, 1);

   fout << "Линейная модель: " << std::endl;

   for (int i = 0; i < 50; ++i){
   ekb_1 = need - y;

   u = calc__uk(ekb_1, ekb_2, ekb_3);
   y = linear.calcPIDMod(start, u);

   fout << "E=" << ekb_1 << " Y=" << y << " U=" << u << std::endl;

   ekb_3 = ekb_2;
   ekb_2 = ekb_1;
   }

   ekb_2 = 0;
   ekb_3 = 0;
   y = start;
   setpoint_ = 0;

   fout << "Нелинейная модель: " << std::endl;

   NonModPID nonLinear(1, 0.0033, 0.525, 0.525, 1);

   for (int i = 0; i < 50; ++i){
   ekb_1 = need - y;

   u = calc__uk(ekb_1, ekb_2, ekb_3);
   y = nonLinear.calcPIDMod(start, u);

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
   * Создаём объект класса RegulPID и вызываем метод для рассчёта и записи результатов в файл
   *
   * Код:
   * \code
   * setlocale(0, "");
   * RegulPID object(10,10,50,0.1);
   * object.PIDCalcWrit(5, 2);
   * std::cout << "Данные были сохранены в файл results.txt" << std::endl;
   * return 0;
   * \endcode
   */
   setlocale(0, "");

   RegulPID object(10, 10, 40, 0.1);

   object.PIDCalcWrit(5, 2);

   std::cout << "Данные были сохранены в файл results.txt" << std::endl;

   return 0;
}