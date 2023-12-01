<p align="center"> Министерство образования Республики Беларусь
<p align="center">Учреждение образования
<p align="center">“Брестский Государственный технический университет”
<p align="center">Кафедра ИИТ
<br><br><br>
<p align="center">Лабораторная работа №4
<p align="center">По дисциплине “Теория и методы автоматического управления”
<p align="center">Тема: “Работа с контроллером AXC F 2152”
<br><br><br><br><br><br>
<p align="right">Выполнила:
<p align="right">Студентка 3 курса
<p align="right">Группы АС-61
<p align="right">Дубновицкая М.С.
<p align="right">Проверил:
<p align="right">Старший преподаватель
<p align="right">Иванюк Д.С.
<br><br><br>
<p align="center">Брест 2023</p>

---
<p> <strong>Цель: </strong>используя Visual Studio собрать данный проект и показать работоспособность на тестовом контроллере.</p> 

Задание: [#4](../../../../tasks/task_04/readme.md).
<p> <strong>Решение:</strong> </p>

Согласно заданию, клонируем репозиторий [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).

<p>Открываем этот репозиторий (в Visual Studio). Далее, мы получаем проект на основе CMake.</p>
<p>Используя <em>Visual Studio</em> собираем этот проект.</p>
<p>Подключаемся к контроллеру так же как и в <em>3 лабораторной работе:</em> </p>

[task_03](../../task_03/doc/readme.md).

<p>Переходим в папку с проектом и запускаем нашу программу:</p>

``` bash

./ptusa_main  main.plua  sys_path  ./sys/

```

<p>Получаем следуюий вывод на консоль: </p>

![](images/build_run.png)

![](images/console.png)

![](images/main-admin.png)

![](images/photo.png)

<p> <strong> Вывод:</strong> в ходе данной лабораторной работы была изучена работа в среде разработки Visual Studio, собран проект и получены навыки работы на тестовым контроллером AXC F 2152.</p>
