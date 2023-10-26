<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-62</p>
<p align="right">Мухачёва Е.Г.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---

**Задание**:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

**Код решения:**

``` C++
#include <iostream>
#include <cmath>

double linearModel(double inputTemperature_Yt, double inputWarm_U, double a, double b) //Вычисление линейной функции
{
	return (a * inputTemperature_Yt)+(b* inputWarm_U);
}

double nonLinearModel(double inputTemperature_Yt, double inputTemperature_Yt_1, double inputWarm_U, double inputWarm_U_1, double a, double b, double c, double d)  //Вычисление нелинейной функции
{
	return (a * inputTemperature_Yt) - b*pow(inputTemperature_Yt_1,2)+(c*inputWarm_U)+d*sin(inputWarm_U_1);
}

int main() 
{
	const double linearA = 1.6; //создание переменных для вычисления функций
	const double linearB = 0.9;
	const double nonLinearA = 0.8;
	const double nonLinearB = 0.6;
	const double nonLinearC = 0.5;
	const double nonLinearD = 0.3;

	double linearY = 0.0;
	double nonLinearY = 0.0;
	double previousNonLinearY = 0.0;

	double inputU = 0;
	double previousInputU = 0;

	int timeT;

	std::cout << "enter Warm: ";
	std::cin >> inputU;
	std::cout << "enter Time: ";
	std::cin >> timeT;
	std::cout << "\n";

	for (int i = 1; i <= timeT; i++) //Цикл для моделирования временных шагов
	{
		linearY = linearModel(linearY, inputU, linearA, linearB);
		nonLinearY = nonLinearModel(nonLinearY, previousNonLinearY, inputU, previousInputU, nonLinearA, nonLinearB, nonLinearC, nonLinearD);
		previousNonLinearY = nonLinearY;	
		previousInputU = inputU;

		
		std::cout << "TIME: " << i << std::endl;
		std::cout << "LINEAR MODEL: " << linearY << std::endl;
		std::cout << "NONLINEAR MODEL: " << nonLinearY << std::endl<<std::endl;
		
	}


}

Пример вывода программы:

``` bash
enter Warm: 0.9
enter Time: 7

TIME: 1
LINEAR MODEL: 0.81
NONLINEAR MODEL: 0.45

TIME: 2
LINEAR MODEL: 2.106
NONLINEAR MODEL: 0.923498

TIME: 3
LINEAR MODEL: 4.1796
NONLINEAR MODEL: 0.912087

TIME: 4
LINEAR MODEL: 7.49736
NONLINEAR MODEL: 0.915526

TIME: 5
LINEAR MODEL: 12.8058
NONLINEAR MODEL: 0.914506

TIME: 6
LINEAR MODEL: 21.2992
NONLINEAR MODEL: 0.91481

TIME: 7
LINEAR MODEL: 34.8888
NONLINEAR MODEL: 0.91472
```