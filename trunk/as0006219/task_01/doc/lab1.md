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
<p align="right">Тупик Д.А.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д.С.</p>
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
using namespace std;
double linMod(double inputTemperature_Yt, double inputWarm_U, double a, double b)
{
	return (a * inputTemperature_Yt) + (b* inputWarm_U);
}
double nolMod(double inputTemperature_Yt, double inputTemperature_Yt_1, double inputWarm_U, double a, double b, double c, double d) 
{
	return (a * inputTemperature_Yt) - b * pow(inputTemperature_Yt_1, 2) + (c*inputWarm_U) + d * sin(inputWarm_U);
}
int main(){
	setlocale(LC_ALL, "rus");
	double lina = 1.6; 
	double linb = 0.9;
	double nola = 0.8;
    double nolb = 0.6;
	double nolc = 0.5;
	double nold = 0.3;
	double liny = 0.0;
	double noly = 0.0;
	double prenoly = 0.0;
	double W = 0;
	int t;

	cout << "Введите тепло: ";
	cin >> W;

	cout << "Введите время: ";
	cin >> t;

	cout << endl;

	for (int i = 1; i <= t; i++) 
	{
		liny = linMod(liny, W, lina, linb);
		noly = nolMod(noly, prenoly, W, nola, nolb, nolc, nold);
		prenoly = noly;
		cout << "Время: " << i << endl;
		cout << "Линейная модель: " << liny << endl;
		cout << "Нелинейная модель: " << noly << endl << endl;
	}
}
Результат программы:

Введите тепло: 2
Введите время: 3

Время: 1
Линейная модель: 1.8
Нелинейная модель: 1.27279

Время: 2
Линейная модель: 4.68
Нелинейная модель: 1.31903

Время: 3
Линейная модель: 9.288
Нелинейная модель: 1.28411
```