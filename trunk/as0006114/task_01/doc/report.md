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
<p align="right">Поцелуйко М.А.</p>
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

void linearModel(float A, float B, float temp, float warm, int time)
{
    cout << endl << "LinearModel:" << endl << endl;

    float currentTemp = temp;

    for (int i = 0; i < time; i++)
    {
        currentTemp = A * currentTemp + B * warm;

        cout << "y(" << i + 1 << ") = " << currentTemp << endl;
    }

    cout << endl;
}

void nonLinearModel(float A, float B, float C, float D, float temp, float warm, int time)
{
    cout << "NonLinearModel:" << endl << endl;

    float* temps = new float[time];

    for (int i = 0; i < time; i++)
    {
        int currentTemp, prevTemp;

        if (i == 0)
        {
            currentTemp = temp;
            prevTemp = temp;
        }
        else if(i == 1)
        {
            currentTemp = temps[i - 1];
            prevTemp = temp;
        }
        else
        {
            currentTemp = temps[i - 1];
            prevTemp = temps[i - 2];
        }

        temps[i] = A * currentTemp - B * pow(prevTemp, 2) + C * warm + D * sin(warm);

        cout << "y(" << i + 1 << ") = " << temps[i] << endl;
    }

    delete[] temps;
}

int main()
{
    setlocale(LC_ALL, "rus");

    const float A = 0.8;
    const float B = 0.5;
    const float C = 2.1;
    const float D = 1.3;
    
    float temp, warm;
    int time;

    cout << "Введите температуру объекта: ";
    cin >> temp;
    
    cout << "Введите значение температуры warm:";
    cin >> warm;

    cout << "Введите ограничение по времени:";
    cin >> time;

    linearModel(A, B, temp, warm, time);
    nonLinearModel(A, B, C, D, temp, warm, time);

    return 0;
}

Результаты работы программы:

``` bash
Input object temperature: 5
Input warm:10
Input time limit:10

------------------------
LinearModel:

y(1) = 9
y(2) = 12.2
y(3) = 14.76
y(4) = 16.808
y(5) = 18.4464
y(6) = 19.7571
y(7) = 20.8057
y(8) = 21.6446
y(9) = 22.3156
y(10) = 22.8525

------------------------
NonLinearModel:

y(1) = 11.7928
y(2) = 16.5928
y(3) = -27.4072
y(4) = -129.307
y(5) = -447.407
y(6) = -8657.81
y(7) = -106810
y(8) = -3.75573e+07
y(9) = -5.73413e+09
y(10) = -7.05275e+14

------------------------
```