<p align="center">Ministry of Education of the Republic of Belarus</p>
<p align="center">Educational institution</p>
<p align="center">Brest State Technical University</p>
<p align="center">Department of IIT</p>
<br><br><br><br><br><br>
<p align="center"><strong>Laboratory work No.3</strong></p>
<p align="center"><strong>By discipline</strong> “"Working with the AXCF 2152 controller"”</p>
<p align="center"><strong>Subject:</strong> “Modeling the temperature of an object”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Completed </strong>:</p>
<p align="right">3rd year student</p>
<p align="right">AC-61 groups</p>
<p align="right">Linkevich P.S.</p>
<p align="right"><strong>Checked:</strong></p>
<p align="right">Ivanyuk D. S.</p>
<br><br><br><br><br>
<p align="center"><strong>Brest 2023</strong></p>

---
***Цель:***
<br>
Научиться сборке и запуску проекта на контроллере AXCF 2152.
<br><br><br>
***Задание***:
<br>
``` bash
1) Ознакомиться с платформой PLCnext.
2) Изучить руководство.
3) Используя Visual Code создать тестовый проект "Hello PLCnext from AS006111!", собрать его и продемонстрировать работоспособность на тестовом контроллере.
4) Написать отчет в Morkdown формате (readme.md) и разместить pull request в следующем каталоге: trunk\as0006111\task_03\doc.
```
<br><br><br>

***Последовательность действий:***
<br>
• Делаем fork репозитрия savushkin-r-d/PLCnext-howto.<br>
• Устанавливаем CMake, Cmake Tool,WinSCP, PuTTy, MinGW, MVS19 (через него открываем PLCnext-howto/HowTo build program/ Hello PLCnext).<br>
• В cpp файле меняем часть на "as006111".<br>
• В PLCnext-howto-master/HowTo build program Hello PLCnext/Hello-PLCnext/CmakeCashe в строку "CMAKE_MAKE_PROGRAM:FILEPATH" прописываем путь к ninja.<br>
• Пересобиаем проект.<br>
• В панели управления "Сеть и Интернет / Центр управления сетями и общим доступом" выбираем  сеть Ethernet, вводим ip 192.168.1.1 и маску 255.255.255.0, PuTTy прописываем ip 192.168.1.10.<br>
<br>
![](../../images/Connection.png)
<br>
• Прописываем ip в WinSCP и указываем имя пользователя "admin".(Пароль написан на самом контроллере)<br>
• Файл hello_PLCnext перемещаем в файловую систему контроллера, даём все расширения и права. <br>
• Вводим в терминал "./hello_PLCnext" - это запуск проекта. <br>
Вывод программы: "Hello PLCnext from as006111". <br><br>
![](../../images/Conclusion.png)
<br><br>
<strong><em>Вывод:</em></strong>
<p>В ходе лабораторной работы мы научились собирать проект для контроллера AXCF 2152 и запускать его. </p>

![](../../images/Laboratory.png)

