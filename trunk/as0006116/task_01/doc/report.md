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
	 //Константы
    const double A_means_AncientApparation = 1.1;
    const double B_means_BountyHunter = 0.03;
    const double C_means_CentaurWarrunner = 0.7;
    const double D_means_DarkSeer = 0.06;
    double Ytemp = 0;
    double Uwarm = 0;
    double Ytemp_1 = 17;
    double Uwarm_1 = 19;
	 //ВВод данных
    cout << "Input temperature: ";
    cin >> Ytemp;
    cout << "Input warm: ";
    cin >> Uwarm;
	 double Temprature_means_TrollWarlord[15] = { 0 };
    Temprature_means_TrollWarlord[0] = Ytemp_1;
    Temprature_means_TrollWarlord[1] = Ytemp;
	 //Вычисления по формуле линейной модели
	 for (int index_of_copypast = 2; index_of_copypast < 15; index_of_copypast++) { Temprature_means_TrollWarlord[index_of_copypast] = A_means_AncientApparation * Temprature_means_TrollWarlord[index_of_copypast - 1] + B_means_BountyHunter * Uwarm; }
    cout << "For linear model:\n";
    for (int second_index = 0; second_index < 15; second_index++) cout << "Temperature at the " << second_index << " time: " << Temprature_means_TrollWarlord[second_index] << (Temprature_means_TrollWarlord[second_index]>20?". It is soo good)))":". It is soo hot(((") <<" \n";
	 cout << "\n";
	 //Вычисления по формуле нелинейной модели
    for (int third_index = 2; third_index < 15; third_index++) { Temprature_means_TrollWarlord[third_index] = A_means_AncientApparation * Temprature_means_TrollWarlord[third_index - 1] - B_means_BountyHunter * pow(Temprature_means_TrollWarlord[third_index - 2], 2) + C_means_CentaurWarrunner * Uwarm + D_means_DarkSeer * sin(Uwarm_1); }
    cout << "For nonlinear model:\n";
    for (int some_other_index = 0; some_other_index < 15; some_other_index++) cout << "Temperature at the "<< some_other_index <<" time: " << Temprature_means_TrollWarlord[some_other_index] << (Temprature_means_TrollWarlord[some_other_index]>20?". It is soo good)))":". It is soo hot(((") << " \n";
	 return 0;
}
```

Пример вывода программы:

``` bash
Input temperature: 10
Input warm: 12
For linear model:
Temperature at the 0 time: 17. It is soo hot(((
Temperature at the 1 time: 10. It is soo hot(((
Temperature at the 2 time: 11.36. It is soo hot(((
Temperature at the 3 time: 12.856. It is soo hot(((
Temperature at the 4 time: 14.5016. It is soo hot(((
Temperature at the 5 time: 16.3118. It is soo hot(((
Temperature at the 6 time: 18.3029. It is soo hot(((
Temperature at the 7 time: 20.4932. It is soo good)))
Temperature at the 8 time: 22.9026. It is soo good)))
Temperature at the 9 time: 25.5528. It is soo good)))
Temperature at the 10 time: 28.4681. It is soo good)))
Temperature at the 11 time: 31.6749. It is soo good)))
Temperature at the 12 time: 35.2024. It is soo good)))
Temperature at the 13 time: 39.0826. It is soo good)))
Temperature at the 14 time: 43.3509. It is soo good)))

For nonlinear model:
Temperature at the 0 time: 17. It is soo hot(((
Temperature at the 1 time: 10. It is soo hot(((
Temperature at the 2 time: 10.739. It is soo hot(((
Temperature at the 3 time: 17.2219. It is soo hot(((
Temperature at the 4 time: 23.8933. It is soo good)))
Temperature at the 5 time: 25.7938. It is soo good)))
Temperature at the 6 time: 19.6555. It is soo hot(((
Temperature at the 7 time: 10.0704. It is soo hot(((
Temperature at the 8 time: 7.8963. It is soo hot(((
Temperature at the 9 time: 14.0525. It is soo hot(((
Temperature at the 10 time: 21.9962. It is soo good)))
Temperature at the 11 time: 26.6806. It is soo good)))
Temperature at the 12 time: 23.2427. It is soo good)))
Temperature at the 13 time: 12.6203. It is soo hot(((
Temperature at the 14 time: 6.08461. It is soo hot(((
```

**Вывод**:
В результате выполнения задания были получены практические навыки в работе с Git. Продуманный, лёгкий, надёжный сервис, GitHub не в последнюю очередь - один из двигателей open-source. "Выложить на GitHub" - наверное, первое, что приходит в голову, если код перерастает из досужего в нечто, что может использовать не только его автор. GitHub - это и хостинг для вашего кода, и вики, и диффы, и отслеживание истории изменений, и, кроме прочего, прекрасный инструмент для самообучения, причём двустороннего. Во-первых, всегда можно посмотреть, как другие разработчики подходят к имеющейся проблеме, или узнать, как устроен инструмент, которым вы пользуетесь. Во-вторых, из пулл-реквестов к выложенной вами "либе для себя" можно почерпнуть много полезного. Вообще, когда есть сервис, который берёт на себя одну из задач, стоящих перед начинающим проект: хостинг кода и совместную работу над ним, а в случае с GitHub ещё и решает её с таким блеском, то чего же ещё желать?