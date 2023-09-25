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
<p align="right">Группы АС-61</p>
<p align="right">Седко М. В.</p>
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
using namespace std;
int main()
{
    const double a = 1.1;
    const double b = 0.03;
    const double c = 0.7;
    const double d = 0.06;
    double Ytemp = 0;
    double Uwarm = 0;
    double Ytemp_1 = 17;
    double Uwarm_1 = 19;
    cout << "Input temperature: ";
    cin >> Ytemp;
    cout << "\nInput warm: ";
    cin >> Uwarm;
    cout << "\n";
    double y[15] = { 0 };
    y[0] = Ytemp_1;
    y[1] = Ytemp;
    for (int i = 2; i < 15; i++) {
        y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * Uwarm + d * sin(Uwarm_1);
    }
    cout << "For nonlinear model:\n";
    for (int i = 0; i < 15; i++) cout << "y["<< i <<"] = " << y[i] << " \n";
    cout << "\n";
    for (int i = 2; i < 15; i++) {
        y[i] = a * y[i - 1] + b * Uwarm;
    }
    cout << "For linear model:\n";
    for (int i = 0; i < 15; i++) cout << "y[" << i << "] = " << y[i] << " \n";
    return 0;
}
```

Пример вывода программы:

``` bash
Input temperature: 21

Input warm: 25

For nonlinear model:
y[0] = 17
y[1] = 21
y[2] = 31.939
y[3] = 39.4119
y[4] = 30.2591
y[5] = 4.19509
y[6] = -5.34478
y[7] = 11.1018
y[8] = 28.8639
y[9] = 45.5618
y[10] = 42.6332
y[11] = 2.12907
y[12] = -34.6768
y[13] = -20.7714
y[14] = -41.4139

For linear model:
y[0] = 17
y[1] = 21
y[2] = 23.85
y[3] = 26.985
y[4] = 30.4335
y[5] = 34.2269
y[6] = 38.3995
y[7] = 42.9895
y[8] = 48.0384
y[9] = 53.5923
y[10] = 59.7015
y[11] = 66.4217
y[12] = 73.8138
y[13] = 81.9452
y[14] = 90.8897

```