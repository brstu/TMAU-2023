<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br>
<p align="center">Лабораторная работа №4</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Работа с контроллером AXC F 2152”</p>
<br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-61</p>
<p align="right">Леонович А.А.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2023</p>

---
<p> <strong>Цель: </strong>используя <em>Visual Studio</em> собрать данный проект и продемонстрировать работоспособность на тестовом контроллере.</p> 

<p> <strong>Решение:</strong> </p>

По заданию, клонируем репозиторий [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).

<p>Мы открываем этот репозиторий в <em>Visual Studio</em>, что позволяет нам создать проект на базе <em>CMake</em>.</p>
<p>С помощью <em>Visual Studio</em> мы компилируем этот проект.</p> 
<p>Затем мы подключаемся к контроллеру, следуя тем же шагам, что и в <em>3-й лабораторной работе:</em> </p>

[task_03](../../task_03/doc/readme.md).

<p>Переходим в папку с проектом и запускаем нашу программу:</p>

``` bash

./ptusa_main  main.plua  sys_path  ./sys/

```

<p>Получаем результат в виде следущего вывода в консоли: </p>

![](images/main-admin.png)

![](images/notebookscreen.png)

![](images/screenshot_workpage.png)

![](images/console.png)

![](images/together.png)

 Вывод: в ходе выполнения данной лабораторной работы были получены знания работы в среде разработки Visual Studio, а также был собран проект и получены дополнительные навыки работы на тестовым контроллером AXC F 2152.