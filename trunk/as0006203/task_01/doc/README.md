<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-62</p>
<p align="right">Гомон М.Д.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2023</p>

---
<p> <strong> Цель: </strong>создать программу на языке программирования c++, моделирующую температуру некого объекта с использованием линейной и нелинейной математической модели, описанными в условии задачи.</p>
<p> <strong> Задание: </strong> </p>

1. Предварительное задание [#0](../../../../tasks/task_00/readme.md).
2. Основное задание [#1](../../../../tasks/task_01/readme.md).

<p> <strong> Решение </strong> </p>
<p> <strong>1) </strong>Создадим сборку с помощью <em>cMake</em>.</p>
<p> <strong>2) </strong>Для начала на диске <em>D:\</em> создадим директорию <em>testLab</em>.</p>
<p> <strong>3) </strong>В данной директории создадим 2 под-директории: <em>lab01</em>, для файлов, содержащих исходный код программы и скрипт сборки проекта и <em>build</em> содержащую, непосредственно сборку нашего проекта.</p>
<p> <strong>4) </strong>В директорию <em>lab01</em> поместим 2 файла:</p>
<ul>
<li><em>main.cpp</em> с кодом программы для моделирования температуры объекта посредством линейной и нелинейной модели.</li>
<li><em>CMakeLists.txt</em> с скриптом сборки проекта.</li>
</ul>
<p> <strong>5) </strong>Откроем консоль и введём следующие команды:</p>
<ul>
<li>Переход в дирректорию <em>build</em> для сборки проекта:</li>

``` bash
cd /d d:\testLab\build
```

<li>Сборка проекта с помощью <em>cMake</em>:</li>

``` bash
cmake d:\testLab\lab01
```

</ul>

<p> <strong>6) </strong>Получим следующий вывод на консоль: </p>

``` bash
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.17763.
-- The C compiler identification is MSVC 19.37.32824.0
-- The CXX compiler identification is MSVC 19.37.32824.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: D:/visual-studio/VC/Tools/MSVC/14.37.32822/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: D:/visual-studio/VC/Tools/MSVC/14.37.32822/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (3.5s)
-- Generating done (0.0s)
-- Build files have been written to: D:/testLab/build
```
<p> <strong>7) </strong>Сборка с помощью <em>cMake</em> прошла успешно. Запускаем наш проект с помощью компилятора.</p>

<p> <strong>8) </strong>Вывод нашей программмы на консоль:

``` bash
Input initial temperature: 12
Input warming value: 12
For linear model:
y[1] = 9.6
y[2] = 6.72
y[3] = 3.264
y[4] = -0.8832
y[5] = -5.85984
y[6] = -11.8318
y[7] = -18.9982
y[8] = -27.5978
y[9] = -37.9174
y[10] = -50.3008
y[11] = -65.161
y[12] = -82.9932
y[13] = -104.392
y[14] = -130.07
y[15] = -160.884
For nonlinear model:
y[2] = 23.6273
y[3] = 39.5001
y[4] = 64.1584
y[5] = 100.097
y[6] = 153.088
y[7] = 231.051
y[8] = 345.804
y[9] = 514.692
y[10] = 763.26
y[11] = 1129.1
y[12] = 1667.53
y[13] = 2459.98
y[14] = 3626.29
y[15] = 5342.85
```
<p> <strong> Вывод:</strong> В ходе выполнения данной лабораторной работы были получены знания для работы с кроссплатформенной системой автоматизации сборки программного обеспечения <em>cMake</em>, а так же приобретены навыки работы с <em>git</em> и <em>github</em>, а именно знания для эффективного управления версиями кода и совместной работы над проектами.</p>