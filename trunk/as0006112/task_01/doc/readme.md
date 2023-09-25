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
<p align="right">Лис С.С.</p>
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

``` cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class TemperatureModel {
public:
    double temp;
    double warm;
    int t;

    TemperatureModel(double temp, double warm, int t) {
        this->temp = temp;
        this->warm = warm;
        this->t = t;
    }

    std::string toString() const {
        return "{ y(t): " + std::to_string(this->temp) + "; t: " + std::to_string(this->t) + " }";
    }
};

const double A = 0.5;
const double B = 1;
const double C = 1.2;
const double D = 0.4;
const double WARM = 1;

void showData(std::vector<TemperatureModel>& tempModels) {
    for (const auto& model : tempModels) {
        std::cout << model.toString() << std::endl;
    }
}

std::vector<TemperatureModel> simulateLinearModel(int time, double temp) {
    std::vector<TemperatureModel> linearTemps;

    for (int t = 1; t <= time; t++) {
        double curWarm = WARM;
        temp = round((A * temp + B * curWarm) * 100) / 100;
        linearTemps.push_back(TemperatureModel(temp, curWarm, t));
    }

    return linearTemps;
}

std::vector<TemperatureModel> simulateNonLinearModel(int time, double temp) {
    std::vector<TemperatureModel> nonLinearTemps;
    double prevTemp = 0;
    double prevWarm = 0;

    for (int t = 1; t <= time; t++) {
        double curWarm = WARM;
        temp = A * temp - B * pow(prevTemp, 2) + C * curWarm + D * sin(prevWarm);
        temp = round(temp * 100) / 100;
        nonLinearTemps.push_back(TemperatureModel(temp, curWarm, t));
        prevTemp = temp;
        prevWarm = curWarm;
    }

    return nonLinearTemps;
}




int main() {
    int time;
    std::cout << "Input time parameter: ";
    std::cin >> time;

    int temp;
    std::cout << "Input initial temperature: ";
    std::cin >> temp;

    std::cout << "Linear model data" << std::endl;
    auto linear = simulateLinearModel(time, temp);
    showData(linear);

    std::cout << "Non linear model data" << std::endl;
    auto nonLinear = simulateNonLinearModel(time, temp);
    showData(nonLinear);

    return 0;
}
```

Пример вывода программы:

``` bash
Input time parameter: 5
Input initial temperature: 6
Linear model data
{ y(t): 4.000000; t: 1 }
{ y(t): 3.000000; t: 2 }
{ y(t): 2.500000; t: 3 }
{ y(t): 2.250000; t: 4 }
{ y(t): 2.130000; t: 5 }
Non linear model data
{ y(t): 4.200000; t: 1 }
{ y(t): -14.000000; t: 2 }
{ y(t): -201.460000; t: 3 }
{ y(t): -40685.330000; t: 4 }
{ y(t): -1655316418.340000; t: 5 }
```