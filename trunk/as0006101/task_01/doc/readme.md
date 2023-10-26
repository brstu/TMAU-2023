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
<p align="right">Баюн Н.О.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---
<p> <strong> Цель: </strong>создать программу на языке программирования c++, моделирующую температуру некого объекта с использованием линейной и нелинейной математической модели, описанными в условии задачи.</p>
<p>Задание:</p>
1. Написать отчет по выполненной лабораторной работе №1 в Markdown формате (readme.md) и с помощью запроса на внесение изменений (pull request) разместить его в следующем каталоге: trunk\as000xxyy\task_01\doc.
2. Исходный код написанной программы разместить в каталоге: trunk\as000xxyy\task_01\src.
3. Выполнить рецензирование (review, checklist) запросов других студентов (минимум 2-е рецензии).

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

Пример вывода программы:

``` bash
Параметры линейной модели
Введите a:      2
Введите b:      1
Введите y:      2
Введите u:      1

Количество тестов
Линейная модель: 2
Нелинейная модель: 1

Линейная модель
Введите ut: 3
Шаг: 1; yt: 7
Введите ut: 2
Шаг: 2; yt: 16

Нелинейная модель
Введите ut: 2
Шаг: 1; yt: 11.42


```