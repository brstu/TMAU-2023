Министерство образования Республики Беларусь

Учреждение образования

«Брестский Государственный технический университет»

Кафедра ИИТ



**Лабораторная работа №1**

По дисциплине «Теория и методы автоматизированного управления»

«Задание 1»








**Выполнил:**

Студент 3 курса

Группы АС-61

Ткачук М. Д.

**Проверил:** 

Иванюк Д. С.





Брест 2023

**Цель:** выполнить задание на языке C++, написать отчет в Markdown, разместить отчет и исходный код программы в указанных каталогах, выполнить рецензирование запросов других студентов.

` `**Текст программы:**

#include <iostream>

#include <cmath>

using namespace std;

class TempController

{

`    `const double A = 2.3;

`    `const double B = 0.7;

`    `const double C = 1.5;

`    `const double D = 2;

`    `const double WARM = 1;

`    `double time;

`    `double temperature;

`    `double warm;



public:

`    `TempController(double time, double temperature, double warm) 

`    `{

`        `this->temperature = temperature;

`        `this->time = time;

`        `this->warm = warm;

`    `}

`    `double NonLinearSimulation()

`    `{

`        `double start\_temperature = 1, start\_warm = 1;

`        `double simulation = A \* this->temperature - B \* pow(start\_temperature, 2) + C \* this->warm + D \* sin(start\_warm);

`        `return simulation;

`    `}

`    `double LinearSimulation()

`    `{

`        `double y = A \* this->temperature + B \* this->warm;

`        `return y;

`    `}

};

int main()

{

`    `setlocale(LC\_ALL, "rus");

`    `double time, temperature, warm;

`    `cout << "Введите температуру в комнате:" << endl;

`    `cin >> temperature;

`    `cout << "Введите момент времени на данный момент:" << endl;

`    `cin >> time;

`    `cout << "Введите количество тепла в комнате:" << endl;

`    `cin >> warm;

`    `TempController tmp(time, temperature, warm);

`    `cout << "Нелинейная модель y(t) = " << tmp.NonLinearSimulation() << endl;

`    `cout << "Линейная модель y(t) = " << tmp.LinearSimulation() << endl;

`    `system("pause");

`    `return 0;

}

**Пример работы программы:**

![](Aspose.Words.fe4501d8-9ac2-46c4-8d7e-ce3eb6df97ea.001.png)

**Вывод:** выполнили задание на языке C++, написали отчет в Markdown, разместили отчет и исходный код программы в указанных каталогах, выполнили рецензирование запросов других студентов.

