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
<p align="right">Леонович А. А.</p>
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

```

Пример вывода программы:

``` bash
choose :
 1 - linear
 2 - nonlinear
1
enter temperature
2
enter choosen_warm
4

y[0]=2
y[1]=0.24
y[2]=0.064
y[3]=0.0464
y[4]=0.04464
y[5]=0.044464
y[6]=0.0444464
y[7]=0.0444446
y[8]=0.0444445
y[9]=0.0444444
y[10]=0.0444444
y[11]=0.0444444
y[12]=0.0444444
y[13]=0.0444444
y[14]=0.0444444
y[15]=0.0444444
Press any key to continue . . .

choose :
 1 - linear
 2 - nonlinear
2
enter temperature
12
enter choosen_warm
4

y[0]=12
y[1]=1.24
y[2]=-1.21114
y[3]=-0.0316257
y[4]=0.0870329
y[5]=0.113557
y[6]=0.116144
y[7]=0.116349
y[8]=0.116364
y[9]=0.116365
y[10]=0.116365
y[11]=0.116365
y[12]=0.116365
y[13]=0.116365
y[14]=0.116365
y[15]=0.116365
Press any key to continue . . .


```