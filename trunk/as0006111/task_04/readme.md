<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №4</strong></p>
<p align="center"><strong>По дисциплине</strong> “"Работа с контроллером AXCF 2152"”</p>
<p align="center"><strong>Тема:</strong> “Моделирования температуры объекта”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Выполнила</strong>:</p>
<p align="right">Студентка 3 курса</p>
<p align="right">Группы АС-61</p>
<p align="right">Линкевич П.С.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2023</strong></p>

---
***Цель:***
Научиться сборке и запуску проекта на контроллере AXCF 2152.
<br><br><br>
***Задание***:
``` bash
1) Ознакомиться с общей информацией о платформе PLCnext здесь.
2) Изучить проект ptusa_main.
3) Используя Visual Studio собрать данные проект и продемонстрировать работоспособность на тестовом контроллере.
4)Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_04\doc.
<br><br><br>
```

***Последовательность действий:***
<br>
Клонируем репозиторий <br>

``` bash
[ptusa_main](https://github.com/savushkin-r-d/ptusa_main).
```
<p>Открываем этот репозиторий в <strong>Visual Studio</strong>, создаем проект на базе <strong>CMake</strong>.</p>
<p>С помощью <strong>Visual Studio</strong>  компилируем проект.</p> 
<p>Подключаемся к контроллеру, по тому же принципу, что и в 3 лабораторной работе: </p>

[task_03](../../task_03/doc/readme.md).
<br>

![](images/cont_files.png)
<br>

Переходим в папку с проектом и запускаем программу:<br>

``` bash

./ptusa_main  main.plua  sys_path  ./sys/

```

<br>
Получаем результат в виде следущего вывода в консоли: <br>

![](../../images/conclusion2.png)

![](../../images/laptop.png)


<br><br>
<strong><em>Вывод:</em></strong>
<p>В ходе лабораторной работы мы научились собирать проект для контроллера AXCF 2152 и запускать его. </p>

![](../../images/lab.png)