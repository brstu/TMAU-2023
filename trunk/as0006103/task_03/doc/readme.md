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
Мы делаем форк репозитория savushkin-r-d/PLCnext-howto.<br> 
Устанавливаем CMake, Cmake Tool,WinSCP, PuTTy, MinGW, MVS19 (через него открываем PLCnext-howto/HowTo build program/ Hello PLCnext).<br> 
Внесем изменения в cpp файл, заменив часть на as006103.<br> 
Открываем PLCnext-howto-master/HowTo build program Hello PLCnext/Hello-PLCnext/CmakeCashe и прописываем путь к ninja в строку "CMAKE_MAKE_PROGRAM:FILEPATH".<br> 
Затем пересобираем проект.<br> 
Выбираем сеть Ethernet в панели управления "Сеть и Интернет/Центр управления сетями и общим доступом", вводим ip 192.168.1.1 и маску 255.255.255.0, а также указываем ip 192.168.1.10 для PuTTy.<br> 
Прописываем ip в WinSCP и указываем имя пользователя "admin" (Пароль написан на самом контроллере).<br> 
Перемещаем файл hello_PLCnext в файловую систему контроллера, предоставляем все расширения и права. <br> 
Затем вводим в терминал "./hello_PLCnext" для запуска проекта. <br> 
Результат программы: "Hello PLCnext from as006103". <br> 

<strong><em>Итог:</em></strong> 
<p>В результате лабораторной работы мы освоили процесс сборки проекта для контроллера AXCF 2152 и его запуска. </p>