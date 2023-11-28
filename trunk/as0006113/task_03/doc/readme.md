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
<p align="right">Группы АС-61</p>
<p align="right">Павлючик А.С.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2023</p>

---

<p> <strong>Цель:</strong> создать тестовый проект "Hello PLCnext from AS0xxyy!", собрать его и продемонстрировать работоспособность на тестовом контроллере.</p>

<p> <strong>Ход работы:</strong> </p>
<p>Для решения поставленной задачи, для начала необходимо собрать файл <em>hello_PLCnext</em> в Visual Studio. Чтобы собрать файл используются следующие команды:</p>

 ``` bash
cmake --preset=build-windows-AXCF2152-2021.9.0.40 .
```

 ``` bash
cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target all .
```

 ``` bash
cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target install .
```

<p>Получаем файл <em>hello_PLCnext</em>.</p>

<p>После того, каксобрали исполняемый файл, подключаемся к контроллеру через Ithernet соединение.</p>

<p align="center"><img style='border:2px solid #000000'src="images/conect.png"/>

<p>Проверяем подключение контроллера.</p>

<p align="center"><img style='border:2px solid #000000'src="images/conect.png"/>

<p>Открываем программу <em>PuTTY Configuration</em> и подключаемся к контроллеру. Вводим логин и пароль.</p>

<p align="center"><img style='border:2px solid #000000'src="images/log.png"/>

<p>Открываем программу <em>WinSCP</em> и подключаемся к контроллеру.</p>

<p align="center"><img style='border:2px solid #000000'src="images/scp.png"/>

<p>Добавляем собраный проект в корень контролера и меняем его разрешения, для запуска.</p>

<p align="center"><img style='border:2px solid #000000'src="images/file.png"/>

<p>Запускаем исполняемый файл и получаем вывод "Hello PLCnext from AS06113!" </p>

<p align="center"><img style='border:2px solid #000000'src="images/work.png"/>
<p align="center"><img style='border:2px solid #000000'src="images/cheklab.png"/>