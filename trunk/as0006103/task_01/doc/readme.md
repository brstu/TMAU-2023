<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №1</strong></p>
<p align="center"><strong>По дисциплине</strong> “Теория и методы автоматического управления”</p>
<p align="center"><strong>Тема:</strong> “Моделирования температуры объекта”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Выполнила</strong>:</p>
<p align="right">Студентка 3 курса</p>
<p align="right">Группы АС-61</p>
<p align="right">Волошко М.В.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2023</strong></p>

---
***Цель:***
Научиться работате с кроссплатформенной системой автоматизации сборки программного обеспечения cMake, изучить некоторые комманды для работы с git и github, атак же написать отчет в формате Markdowm.
<br><br><br>
***Задание***:
<br><br><br>
Давайте возьмем какой-нибудь объект для управления. Мы хотим контролировать его температуру, которую можно описать этим дифференциальным уравнением:
$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)
Где $\tau$ – время; $y(\tau)$ – входная температура; $u(\tau)$ – входной нагрев; $Y_0$ – температура в комнате; $C,RC$ – другие константы.
<br><br><br>
После преобразования мы получаем такие линейную (2) и нелинейную (3) модели:
$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)
Где $\tau$ – дискретные моменты времени ($1,2,3{\dots}n$); $a,b,c,d$ – другие константы.
<br><br><br>
Задача написать программу (**С++**), который имитирует температуру этого объекта.
<br><br><br><br>
***Пример вывода программы:***
<br><br>
``` bash
Liner model                     Iteration number:                       Yt
enter value Ut:6
                                1                               27
enter value Ut:4
                                2                               97
enter value Ut:3
                                3                               303
enter value Ut:2
                                4                               917
enter value Ut:7
                                5                               2779
enter value Ut:8
                                6                               8369
enter value Ut:4
                                7                               25123

Not liner model                 Iteration number:                       Yt
enter value Ut:3
                                1                               125624
enter value Ut:5
                                2                               628130
enter value Ut:6
                                3                               3.14067e+06
enter value Ut:7
                                4                               1.57034e+07
<br><br>
<strong><em>Вывод:</em></strong>
 <p>В ходе лабораторной работы мы научились работать с кроссплатформенной системой автоматизации сборки программного обеспечения cMake, написали отчетв формате Markdown изучили некоторые комманды для работы с git и github: научились копировать репозиторий, добавлять изменения и т.д. </p>
