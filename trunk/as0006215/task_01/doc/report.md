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
<p align="right">Матиевская А.В.</p>
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

// Линейная модель
double linearModel(double Yt, double U, double a, double b) {
    return a * Yt + b * U;
}

// Нелинейная модель
double nonlinearModel(double Yt, double Yt_1, double U, double a, double b, double c, double d) {
    return a * Yt - b * pow(Yt_1, 2) + c * U + d * sin(U);
}

int main() {
    
    double a_linear = 0.8;
    double b_linear = 0.5;
    double a_nonlinear = 0.8;
    double b_nonlinear = 0.5;
    double c_nonlinear = 0.2;
    double d_nonlinear = 0.1;

   
    double Y_linear = 0.0;
    double Y_nonlinear = 0.0;
    double Y_prev_nonlinear = 0.0;

    // Входные значения
    double U = 1.0;

    // Моделирование для 10 временных шагов
    for (int t = 1; t <= 10; t++) {
        // Линейная модель
        Y_linear = linearModel(Y_linear, U, a_linear, b_linear);

        // Нелинейная модель
        Y_nonlinear = nonlinearModel(Y_nonlinear, Y_prev_nonlinear, U, a_nonlinear, b_nonlinear, c_nonlinear, d_nonlinear);
        Y_prev_nonlinear = Y_nonlinear;

        std::cout << "time step: " << t << std::endl;
        std::cout << "Linear model: " << Y_linear << std::endl;
        std::cout << "Nonlinear model: " << Y_nonlinear << std::endl;
        std::cout << "------------------------" << std::endl;
    }

Пример вывода программы:

``` bash
time step: 1
Linear model: 0.5
Nonlinear model: 0.284147
------------------------
time step: 2
Linear model: 0.9
Nonlinear model: 0.471095
------------------------
time step: 3
Linear model: 1.22
Nonlinear model: 0.550058
------------------------
time step: 4
Linear model: 1.476
Nonlinear model: 0.572912
------------------------
time step: 5
Linear model: 1.6808
Nonlinear model: 0.578363
------------------------
time step: 6
Linear model: 1.84464
Nonlinear model: 0.579586
------------------------
time step: 7
Linear model: 1.97571
Nonlinear model: 0.579856
------------------------
time step: 8
Linear model: 2.08057
Nonlinear model: 0.579915
------------------------
time step: 9
Linear model: 2.16446
Nonlinear model: 0.579928
------------------------
time step: 10
Linear model: 2.23156
Nonlinear model: 0.579931
------------------------
```