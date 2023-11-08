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
<p align="right">Иванищева И.А.</p>
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

**Файл с кодом решения находится в папке src**



Пример вывода программы:

``` bash
time step: 1
lin model: 0.7
nl model: 0.936588
------------------------
time step: 2
lin model: 0.91
nl model: 1.34092
------------------------
time step: 3
lin model: 0.973
nl model: 1.24438
------------------------
time step: 4
lin model: 0.9919
nl model: 1.28229
------------------------
time step: 5
lin model: 0.99757
nl model: 1.26852
------------------------
time step: 6
lin model: 0.999271
nl model: 1.27369
------------------------
time step: 7
lin model: 0.999781
nl model: 1.27177
------------------------
time step: 8
lin model: 0.999934
nl model: 1.27248
------------------------
time step: 9
lin model: 0.99998
nl model: 1.27222
------------------------
time step: 10
lin model: 0.999994
nl model: 1.27232
------------------------
```

**Вывод**:
В результате выполнения задания были получены практические навыки в работе с Git. Продуманный, лёгкий, надёжный сервис, GitHub не в последнюю очередь - один из двигателей open-source. "Выложить на GitHub" - наверное, первое, что приходит в голову, если код перерастает из досужего в нечто, что может использовать не только его автор. GitHub - это и хостинг для вашего кода, и вики, и диффы, и отслеживание истории изменений, и, кроме прочего, прекрасный инструмент для самообучения, причём двустороннего. Во-первых, всегда можно посмотреть, как другие разработчики подходят к имеющейся проблеме, или узнать, как устроен инструмент, которым вы пользуетесь. Во-вторых, из пулл-реквестов к выложенной вами "либе для себя" можно почерпнуть много полезного. Вообще, когда есть сервис, который берёт на себя одну из задач, стоящих перед начинающим проект: хостинг кода и совместную работу над ним, а в случае с GitHub ещё и решает её с таким блеском, то чего же ещё желать?
