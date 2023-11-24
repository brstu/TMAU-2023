Министерство образования Республики Беларусь

Учреждение образования

«Брестский Государственный технический университет»

Кафедра ИИТ







**Лабораторная работа №3**

По дисциплине «ТиМАУ»

Тема: «Моделирование объекта управления»



**Выполнил:**

Студент 3 курса

Группы АС-61

Карпович И. В.

**Проверил:** 

Иванюк Д. С.







Брест 2023

Задание: ![](Aspose.Words.30de3b62-aae6-4e6e-9a92-f5a66f1e8be9.001.png "Снимок экрана (7)")

Код задания:

#include <iostream>
#include <cmath>
using namespace std;

class TemperatureController
{
	const double A = 1.2;
	const double B = 0.9;
	const double C = 1.7;
	const double D = 1;
	double temperature;
	double warm;



public:
	TemperatureController(double temperature=0, double warm=0) : temperature(temperature),warm(warm) {
	}
	double LinearSimulation() const {
		double y = A * this->temperature + B * this->warm;
		return y;
	}
	double NonLinearSimulation() const {
		double start_temperature = 1;
		double start_warm = 1;
		double simulation = A * this->temperature - B * pow(start_temperature, 2) + C * this->warm + D * sin(start_warm);
		return simulation;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	double temperature;
	double warm;
	cout << "Введите температуру:"<<endl;
	cin >> temperature;
	cout << "Введите количество тепла:" << endl;
	cin >> warm;
	TemperatureController tmp(temperature, warm);
	cout << "Линейная модель y(t) = " << tmp.LinearSimulation()<<endl;
	cout << "Нелинейная модель y(t) = " << tmp.NonLinearSimulation()<<endl;
	system("pause");
	return 0;
}






Результат работы программы:![](Aspose.Words.30de3b62-aae6-4e6e-9a92-f5a66f1e8be9.002.png "Снимок экрана (6)")
По данным результатам, можем увидеть, что программа симулирует работу контроллера температуры.

Вывод: в ходе работы была разработана программа по моделированию работы объекта управления, изучены основные компоненты платформы GitHub, а также получены полезные практические навыки в работе с языком программирования С++.

