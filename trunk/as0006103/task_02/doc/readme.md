<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №2</strong></p>
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
На C++ реализовать программу, моделирующую рассмотренный выше ПИД-регулятор. В качестве объекта управления использовать математическую модель, полученную в предыдущей работе. Использовать ООП, в программе должно быть не менее 3-х классов (+наследование).
<br>
Написать отчет по выполненной лабораторной работе №2 в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_02\doc. В отчете также привести графики для разных заданий температуры объекта, пояснить полученные результаты.
<br>
В отчет с помощью Doxygen (в .md формате) добавить информацию о разработанной программе (диаграмма классов и т.п.).
<br>
Исходный код написанной программы разместить в каталоге: trunk\as000xxyy\task_02\src.
<br><br><br><br>
***Пример вывода программы:***
<br><br>
``` bash
Number of iteration
Liner Model:4
Not Liner Model:3
enter value y:4
enter value u:3

Liner model
enter value a:45
enter value b:2

Not liner model
enter value a:3
enter value b:5
enter value c:4
enter value d:3


Liner model                     Iteration number:                       Yt
enter value Ut:2
                                1                               184
enter value Ut:4
                                2                               8288
enter value Ut:6
                                3                               372972
enter value Ut:5
                                4                               1.67838

Not liner model                 Iteration number:                       Yt
enter value Ut:3
                                1                               24
enter value Ut:2
                                2                               -2799.58
enter value Ut:1
                                3                               -3.91965
enter value Ut:5
                                4                               -7.68184
Liner Model:
E = 5, Yt = 140, Uk = 2.5
E = -132, Yt = 0, Uk = -67.5
E = 8, Yt = 223.2, Uk = 44.1
E = -215.2, Yt = -110.4, Uk = -122.7
E = 118.4, Yt = 358.72, Uk = 111.86
E = -350.72, Yt = -353.6, Uk = -244.3
E = 361.6, Yt = 663.872, Uk = 264.436
E = -655.872, Yt = -851.136, Uk = -493.068
E = 859.136, Yt = 1346.68, Uk = 605.838
E = -1338.68, Yt = -1891.32, Uk = -1013.16
E = 1899.32, Yt = 2837.19, Uk = 1351.09
E = -2829.19, Yt = -4101.84, Uk = -2118.42
E = 4109.84, Yt = 6054.15, Uk = 2959.58
E = -6046.15, Yt = -8831.1, Uk = -4483.05
E = 8839.1, Yt = 12969.7, Uk = 6417.36
E = -12961.7, Yt = -18971.5, Uk = -9553.24
E = 18979.5, Yt = 27818, Uk = 13841.5
E = -27810, Yt = -40728.6, Uk = -20431.8
E = 40736.6, Yt = 59687.7, Uk = 29776.3
E = -59679.7, Yt = -87418.5, Uk = -43776.8
E = 87426.5, Yt = 128085, Uk = 63974.8
E = -128077, Yt = -187618, Uk = -93876.6
E = 187626, Yt = 274872, Uk = 137368
E = -274864, Yt = -402655, Uk = -201395
E = 402663, Yt = 589891, Uk = 294878
E = -589883, Yt = -864144, Uk = -432140
E = 864152, Yt = 1.26595, Uk = 632908
E = -1.26594, Yt = -1.85454e+06, Uk = -92733
E = 1.85455, Yt = 2.71684, Uk = 1.35835
E = -2.71683, Yt = -3.98003, Uk = -1.99008

Not linear model
E = 5, Yt = -7.68184e+15, Uk = 2.5
E = 7.68184, Yt = 7.68184, Uk = 3.84092
E = -7.68184, Yt = -3.2263, Uk = -6.14547
E = 3.22637, Yt = 6.91366, Uk = 1.92046
E = -6.91366, Yt = -1.8467, Uk = -4.42474
E = 1.84672, Yt = 4.5753, Uk = 1.16303
E = -4.57531, Yt = -1.159, Uk = -2.87854
E = 1.1591, Yt = 2.9186, Uk = 7.31588
E = -2.91867, Yt = -7.3598, Uk = -1.83804
E = 7.35983, Yt = 1.8554, Uk = 4.64045
E = -1.85541, Yt = -4.67755, Uk = -1.16919
E = 4.67755, Yt = 1.1792, Uk = 2.9483
E = -1.17924, Yt = -2.9729, Uk = -7.43212
E = 2.97293, Yt = 7.4949, Uk = 1.87375
E = -7.49491, Yt = -1.88951, Uk = -4.72375
E = 1.88951, Yt = 4.7635, Uk = 1.1908
E = -4.76355, Yt = -1.20092, Uk = -3.00229
E = 1.20092, Yt = 3.02757, Uk = 7.56893
E = -3.02757, Yt = -7.63267, Uk = -1.90817
E = 7.63267, Yt = 1.9242, Uk = 4.81059
E = -1.92424, Yt = -4.8511, Uk = -1.2127
E = 4.8511, Yt = 1.22299, Uk = 3.05747
E = -1.22299, Yt = -3.0832, Uk = -7.70805
E = 3.08322, Yt = 7.77296, Uk = 1.94324
E = -7.77296, Yt = -1.9596e, Uk = -4.89901
E = 1.9596, Yt = 4.94027, Uk = 1.23507
E = -4.94027, Yt = -1.2454, Uk = -3.11367
E = 1.24547, Yt = 3.1398, Uk = 7.84972
E = -3.13989, Yt = -7.9158, Uk = -1.97896
E = 7.91583, Yt = 1.99562, Uk = 4.98905
<br><br>
<strong><em>Вывод:</em></strong>
 <p>В ходе лабораторной работы мы научились работать с кроссплатформенной системой автоматизации сборки программного обеспечения cMake, написали отчетв формате Markdown изучили некоторые комманды для работы с git и github: научились копировать репозиторий, добавлять изменения и т.д. </p>
