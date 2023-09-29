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

**Файл с кодом решения находится в папке src**



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
