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

`	`const double A = 1.2;

`	`const double B = 0.9;

`	`const double C = 1.7;

`	`const double D = 1;

`	`const double WARM = 1;

`	`double time;

`	`double temperature;

`	`double warm;



public:

`	`TemperatureController(double time, double temperature, double warm) {

`		`this->temperature = temperature;

`		`this->time = time;

`		`this->warm = warm;

`	`}

`	`double LinearSimulation() {

`		`double y = A \* this->temperature + B \* this->warm;

`		`return y;

`	`}

`	`double NonLinearSimulation() {

`		`double start\_temperature = 1, start\_warm = 1;

`		`double simulation = A \* this->temperature - B \* pow(start\_temperature, 2) + C \* this->warm + D \* sin(start\_warm);

`		`return simulation;

`	`}

};

int main()

{

`	`setlocale(LC\_ALL, "rus");

`	`double time, temperature, warm;

`	`cout << "Введите температуру:"<<endl;

`	`cin >> temperature;

`	`cout << "Введите момент времени:" << endl;

`	`cin >> time;

`	`cout << "Введите количество тепла:" << endl;

`	`cin >> warm;

`	`TemperatureController tmp(time, temperature, warm);

`	`cout << "Линейная модель y(t) = " << tmp.LinearSimulation()<<endl;

`	`cout << "Нелинейная модель y(t) = " << tmp.NonLinearSimulation()<<endl;

`	`system("pause");

`	`return 0;

}






Результат работы программы:![](Aspose.Words.30de3b62-aae6-4e6e-9a92-f5a66f1e8be9.002.png "Снимок экрана (6)")

Вывод: в ходе работы была разработана программа по моделированию работы объекта управления.





























