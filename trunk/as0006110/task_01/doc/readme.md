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
<p align="right">Леонович А.А.</p>
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

Пример вывода программы:

Пример вывода программы:

``` bash
choose type of transformation:
 0 - linear
 else - nonlinear
1
enter temperature
45
enter warm
13

y[0]=45
y[1]=4.63
y[2]=0.593
y[3]=0.1893
y[4]=0.14893
y[5]=0.144893
y[6]=0.144489
y[7]=0.144449
y[8]=0.144445
y[9]=0.144444
y[10]=0.144444
y[11]=0.144444
y[12]=0.144444
y[13]=0.144444
y[14]=0.144444
y[15]=0.144444
Press any key to continue . . .

choose type of transformation:
 0 - linear
 else - nonlinear
2
enter temperature
45
enter warm
13

y[0]=45
y[1]=4.63
y[2]=-15.803
y[3]=2.18937
y[4]=1.70563
y[5]=4.10666
y[6]=4.36561
y[7]=4.25195
y[8]=4.21864
y[9]=4.22511
y[10]=4.22857
y[11]=4.22838
y[12]=4.22806
y[13]=4.22805
y[14]=4.22807
y[15]=4.22808
Press any key to continue . . .


```