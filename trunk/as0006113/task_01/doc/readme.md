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
<p align="right">Павлючик А.С.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---

**Задание**:



Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

OUT Progam:

``` bash
Input time param: 7
Input initial temper: 2
Linear model data
{ y(t): 4.00; t: 1 }
{ y(t): 3.00; t: 2 }
{ y(t): 2.50; t: 3 }
{ y(t): 2.25; t: 4 }
{ y(t): 2.13; t: 5 }
Non linear model data
{ y(t): 4.20; t: 1 }
{ y(t): 51.00; t: 2 }
{ y(t): 1634561.46; t: 3 }
{ y(t): -13685.33; t: 4 }
{ y(t): -113716418.34; t: 5 }
```