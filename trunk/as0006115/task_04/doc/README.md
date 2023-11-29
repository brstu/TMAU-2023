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
<p align="right">Рыжко С.И.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2023</p>

---
## Цель

Собрать проект [ptusa_main](https://github.com/savushkin-r-d/ptusa_main) и продемонстрировать его работоспособность на контроллере.

## Ход работы

1. Клонируем проект https://github.com/savushkin-r-d/ptusa_main и собираем в исполняемый файл.
   ![](./attachments/build_run_linux.png)
2. Переносим исполняемый файл вместе с демо проектом T1-PLCnext-Demo в файловую систему контроллера с помощью `scp` как это было сделано в [лабораторной работе №3](https://github.com/ryzzax21/TMAU-2023/tree/task_03/trunk/as0006115/task_03).
3. Запускаем бинарный файл в сессии `ssh` с помощью команды `./ptusa_main  main.plua  sys_path ./sys/`
	![](./attachments/run_controller.png)


![](./attachments/demo.jpg)