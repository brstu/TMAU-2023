<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br>
<p align="center">Лабораторная работа №3</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Работа с контроллером AXC F 2152”</p>
<br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-62</p>
<p align="right">Гомон М.Д.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2023</p>

---
<p> <strong>Цель:</strong> создать тестовый проект "Hello PLCnext from AS0xxyy!", собрать его и продемонстрировать работоспособность на тестовом контроллере.</p> 

Задание: [#3](../../../../tasks/task_03/readme.md).
<p> <strong>Решение:</strong> </p>
<p>Клонируем репозиторий и собираем проект с помощью следующих команд</p>

 ``` bash
cmake --preset=build-windows-AXCF2152-2022.6.0.43 .
```


 ``` bash
cmake --build --preset=build-windows-AXCF2152-2022.6.0.43 --target all .
```



 ``` bash
cmake --build --preset=build-windows-AXCF2152-2022.6.0.43 --target install .
```

<p>В результате получим файл <em></em>hello_PLCnext.</p>

![](../images/hello_PLCnext_binary.jpg)  

<p>Подключаемся к контроллеру.</p>


![](../images/connect.jpg)
![](../images/connectionIPV4.jpg)  

<p>Проверяем подключение к контроллеру с помощью команды <em>ping 192.168.1.1</em> и получаем следующий результат</p>

![](../images/check_connection.jpg)  

<p>Устанавливаем и открываем программу <em>PuTTY Configuration</em> и подключаемся к контроллеру.</p>

![](../images/putty_connect.jpg) 

<p>Авторизируемся для подключения к контроллеру</p>

![](../images/putty_login.jpg) 

<p>Устанавливаем и открываем программу <em>WinCP</em> вводим IP adress и авторизируемся.</p>

![](../images/WinSCP_login.jpg) 

<p>Добавляем бинарный файл <em>hello_PLCnext </em> в корень контроллера и меняем его свойства</p>

![](../images/WinSCP_files.jpg) 

<p>Запускаем наш проект и получаем следующий вывод.</p>

![](images/output.jpg) 

![](images/lab.jpg) 

<p> <strong> Вывод:</strong> В ходе выполнения данной лабораторной работы были получены знания для работы с контроллером <em>AXC F 2152</em>.</p>
