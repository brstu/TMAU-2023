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

