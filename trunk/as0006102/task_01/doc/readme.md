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
<p align="right">Василенко И.В.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---

**Задание**:

<p>Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.
</p>
**Решение**:
<p>Создадим сборку с помощью cMake.</p>
<p>Для начала на диске D:\ создадим директорию testLab.</p>
<p>В данной директории оздадим 2 под-директории: lab01 и build.</p>
<p>В директорию lab01 поместим 2 файла:</p>
<ul>
<li>main.cpp с кодом программы.</li>
<li>CMakeLists.txt с скриптом сборки проекта.</li>
</ul>
<p>Откроем консоль и введём следующие команды:</p>
<ul>
<li>Переход в дирректорию для сборки проекта:</li>

``` bash
cd /d d:\testLab\build
```

<li>Сборка проекта с помощью cMake:</li>

``` bash
cmake d:\testLab\lab01
```

</ul>

<p>Получим следующий вывод на консоль: </p>

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
<p>Сборка прошла успешно. Запускаем наш проект с помощью капилятора.</p>

Пример вывода программы в консоль:

``` bash
Enter the constant a 0.7
Enter the constant b 0.4
Enter the constant c 0.3
Enter the constant d 0.1
Enter the warm 1
Enter the  temperature 0
Enter the number of discrete times 10
        ---Temperature modelling using a linear model---
y1 = 0.4
y2 = 0.68
y3 = 0.876
y4 = 1.0132
y5 = 1.10924
y6 = 1.17647
y7 = 1.22353
y8 = 1.25647
y9 = 1.27953
y10 = 1.29567
        ---Temperature modelling using a NON-linear model---
y1 = 0.3
y2 = 0.594147
y3 = 0.76405
y4 = 0.777778
y5 = 0.695083
y6 = 0.62873
y7 = 0.631002
y8 = 0.667728
y9 = 0.692291
y10 = 0.690407
```
**Вывод**:В ходе выполнения данной лаболаторной работы были получены знания для работы с cMake.