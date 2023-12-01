
<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center"> Учреждение образования</p>
<p align="center"> “Брестский Государственный технический университет”</p>
<p align="center"> Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center"> Лабораторная работа №3</p>
<p align="center"> По дисциплине “Теория и методы автоматического управления”</p>
<p align="center"> Тема: “Работа с контроллером AXC F 2152”</p>
<br><br><br><br><br>
<p align="right"> Выполнил:</p>
<p align="right"> Студент 3 курса</p>
<p align="right"> Группы АС-61</p>
<p align="right"> Седко М.В.</p>
<p align="right"> Проверил:</p>
<p align="right"> Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"> Брест 2023</p>

---


## Цель работы:  
 Используя Visual Code создать тестовый проект "Hello PLCnext from AS06116!", собрать его и продемонстрировать работоспособность на тестовом контроллере.
## Ход работы
 Собрал исполняемый файл используя [руководство](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20build%20program%20Hello%20PLCnext). Настромл параметры сети своего компьютера.

 ![](images/Connection1.jpg)

 Пришёл в лабораторию, настроил и подключил контроллер через провод Ethernet к компьютеру.

![](images/MeInLab.jpg)

 Включил PuTTY и поключился к контроллеру.

![](images/Connection2.jpg)

 Открыл WinCP и запустил программу.

![](images/ProgramWorking.jpg)

## Основные проблемы с которыми я столкнулся
 Главной проблемой при сборке стало удаление неправильно установленного SDK. [Решение проблемы](https://www.plcnext-community.net/forum/#/discussion/2428/i-encountered-an-error-when-creating-a-visualstudio-project-plcnext) я нашёл на официальном форуме PLCnext Technology. Также проблемой стало отсутсвие переходника для подключения контроллера к своему компьютеру.
