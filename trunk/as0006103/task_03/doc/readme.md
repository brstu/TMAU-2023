<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №3</strong></p>
<p align="center"><strong>По дисциплине</strong> “"Работа с контроллером AXCF 2152"”</p>
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
Научиться сборке и запуску проекта на контроллере AXCF 2152.
<br><br><br>
***Задание***:
``` bash
1) Ознакомиться с платформой PLCnext.
2) Изучить руководство.
3) Используя Visual Code создать тестовый проект "Hello PLCnext from AS006103!", собрать его и продемонстрировать работоспособность на тестовом контроллере.
4) Написать отчет в Morkdown формате (readme.md) и разместить pull request в следующем каталоге: trunk\as0006103\task_03\doc.
```
<br><br><br>

***Последовательность действий:***
<br>
We fork the repository savushkin-r-d/PLCnext-howto.<br> 
Install CMake, Cmake Tool, WinSCP, PuTTy, MinGW, MVS19 (through which we open PLCnext-howto/HowTo build program/Hello PLCnext).<br> 
Make changes to the cpp file, replacing a part with as006103.<br>
Open PLCnext-howto-master/HowTo build program Hello PLCnext/Hello-PLCnext/CmakeCashe and specify the path to ninja in the "CMAKE_MAKE_PROGRAM:FILEPATH" line.<br> 
Then rebuild the project.<br> 
Select Ethernet network in the control panel "Network and Internet/Network and Sharing Center", enter the IP 192.168.1.1 and subnet mask 255.255.255.0, as well as specify the IP 192.168.1.10 for PuTTy.<br> 
Enter the IP in WinSCP and specify the username "admin" (the password is written on the controller itself).<br> 
Move the hello_PLCnext file to the controller's file system, providing all extensions and permissions. <br> 
result: "Hello PLCnext from as006103". <br> 

<strong><em>Итог:</em></strong> 
<p>As a result of the laboratory work, we mastered the process of building a project for the AXCF 2152 controller and its launch. </p>