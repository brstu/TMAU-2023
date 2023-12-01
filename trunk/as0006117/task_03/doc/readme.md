Министерство образования Республики Беларусь

Учреждение образования

“Брестский Государственный технический университет”

Кафедра ИИТ








Лабораторная работа №3

По дисциплине: «Теория и методы автоматического управления»

Тема: «Работа с контроллером AXC F 2152»














**Выполнил:**

Студент 3 курса

Группы АС-61

Ткачук М. Д.

**Проверил:**

Иванюк Д.С.






Брест 2023

**Цель:** воспользоваться Visual Code и создать тестовый проект "Hello PLCnext from AS0xxyy!", собрать его и показать работоспособность на тестовом контроллере.

**Задание:**

1. Ознакомиться с общей информацией о платформе **PLCnext**.
1. Изучить [руководство](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20build%20program%20Hello%20PLCnext).
1. Используя **Visual Code** создать тестовый проект *"Hello PLCnext from AS0xxyy!"*, собрать его и продемонстрировать работоспособность на тестовом контроллере.
1. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task\_03\doc.

**Ход работы:**

Для выполнения поставленной задачи нам изначально нужно собрать файл *hello\_PLCnext* в Visual Studio. Для этого необходимо воспользоваться командами:

1) cmake --preset=build-windows-AXCF2152-2021.9.0.40 .
1) cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target all .
1) cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target install .\

У нас получается файл «hello\_PLCnext».

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/hello_PLCnext_directory.png](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.001.png)

После выполнения данного пункта, мы идем в лабораторию и подключаемся к контроллеру через Интернет соединение.



Для подключения к контроллеру сначала нужно настроить сеть:

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/connect_check.png](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.002.jpeg)

Затем проверяем подключение к контроллеру:

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/network_configuration.png](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.003.jpeg)




Открывается программа *PuTTY Configuration* для подключения к контроллеру:

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/PuTTY_connect.png]

Вводим логин и пароль (указанный на самом контроллере) для подключения к контроллеру:

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/PuTTY_login.png](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.005.jpeg)

Открываем программу *WinCP* и подключаемся к контроллеру:

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/WinCP_connect.png]

Для запуска контроллера добавляем собранный проект в его корень и меняем разрешение:

![https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/hello_PLCnext_settings.png](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.007.png)

Запускаем проект и получаем вывод:

![](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.008.png)

![](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.009.png)

![](Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.010.jpeg "Scontr")

**Вывод:** В ходе выполнения данной лабораторной работы мы создали и собрали тестовый проект, показали его работоспособность на контроллере *AXC F 2152*.

[https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/PuTTY_connect.png]: Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.004.jpeg
[https://github.com/brstu/TMAU-2023/raw/main/trunk/as0006102/task_03/doc/images/WinCP_connect.png]: Aspose.Words.40f9d141-bf05-4a91-9e87-7721f331b928.006.jpeg
