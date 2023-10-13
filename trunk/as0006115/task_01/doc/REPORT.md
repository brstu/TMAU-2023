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
<p align="right">Рыжко С. B.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---

Цель: написать программу на языке С++, которая моделирует температуру объекта, подверженного воздействию тепла. Для этого необходимо использовать линейную и нелинейную математические модели, описанные в условии задачи.

**Задание**:


На языке C++ симулировать данные 2 модели температуры:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

**Код решения:**

Код решения задачи приведен в фале trunk/as0006115/src/main.cpp

За теплоту принята константа WARM равная 1.

Пример вывода программы:

``` zsh
➜  src git:(task_01) ✗ ./build/tempmodels
Input time parameter: 10

Input initial temperature: 0
Linear model:
temp: 1.00 warm: 1.00 time: 1.00
temp: 1.50 warm: 1.00 time: 2.00
temp: 1.75 warm: 1.00 time: 3.00
temp: 1.88 warm: 1.00 time: 4.00
temp: 1.94 warm: 1.00 time: 5.00
temp: 1.97 warm: 1.00 time: 6.00
temp: 1.98 warm: 1.00 time: 7.00
temp: 1.99 warm: 1.00 time: 8.00
temp: 2.00 warm: 1.00 time: 9.00
temp: 2.00 warm: 1.00 time: 10.00

Non Linear model:
temp: 1.54 warm: 1.00 time: 1.00
temp: 1.30 warm: 1.00 time: 2.00
temp: 1.19 warm: 1.00 time: 3.00
temp: 1.13 warm: 1.00 time: 4.00
temp: 1.10 warm: 1.00 time: 5.00
temp: 1.09 warm: 1.00 time: 6.00
temp: 1.08 warm: 1.00 time: 7.00
temp: 1.08 warm: 1.00 time: 8.00
temp: 1.07 warm: 1.00 time: 9.00
temp: 1.07 warm: 1.00 time: 10.00
.
Press Enter to exit...

```

Вывод: Успешно смоделировали температуру.
