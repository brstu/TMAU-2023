<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №1</strong></p>
<p align="center"><strong>По дисциплине</strong> “Теория и методы автоматического управления”</p>
<p align="center"><strong>Тема:</strong> “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right"><strong>Выполнила</strong>:</p>
<p align="right">Студентка 3 курса</p>
<p align="right">Группы АС-61</p>
<p align="right">Линкевич П.С.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2023</strong></p>

---

***Задание***:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

***Пример вывода программы:***

``` bash
Линейная модель                 Итерация                        Yt
Введите Ut: 3
                        1                       26.85
Введите Ut: 7
                        2                       213.053
Введите Ut: 5
                        3                       1466.65
Введите Ut: 9
                        4                       9983.75

Нелинейная модель               Итерация                        Yt
Введите Ut: 3
                        1                       24.8
Введите Ut: 7
                        2                       -1552.16
Введите Ut: 3
                        3                       -6.70518e+06
Введите Ut: 2
                        4                       -1.24987e+14
```
<br>
<strong><em>Вывод:</em></strong>
 <p>В ходе лабораторной работы мы научились работать с кроссплатформенной системой автоматизации сборки программного обеспечения cMake, а так же изучили некоторые комманды для работы с git и github: научились копировать репозиторий, добавлять изменения и т.д.. </p>
