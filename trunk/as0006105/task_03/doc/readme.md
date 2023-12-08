<p align="center">Министерство образования Республики Беларусь  
<p align="center">Учреждение образования   
<p align="center">Брестский Государственный Технический Университет 
<p align="center">Кафедра ИИТ
<br/><br/><br/>
<p align="center">Лабораторная работа №3</p>
<p align="center">"Работа с контроллером AXCF 2152"</p>
<br/><br/><br/><br/>
<p align="right">Выполнила:  </p>
<p align="right">Студентка 3 курса  </p>
<p align="right">Группы АС-61  </p>
<p align="right">Дубновицкая М.С. </p> 
<p align="right">Проверил:</p>
<p align="right">Иванюк Д.С.</p>
<br/><br/><br/><br/><br/><br/><br/><br/><br/>
<p align="center">Брест 2023

---
<p> <strong> Цель работы:</strong> запустить проект на контроллере AXCF 2152
<br/><br/>
<p> <strong>Ход работы </strong>

Для начала необходимо клонировать репозиторий savushkin-r-d/PLCnext-howto.   
Для сборки проекта потребуется MVS19. Теперь устанавливаем CMake, Cmake Tool и MinGW.   
Через MVS открываем PLCnext-howto/HowTo build program/ Hello PLCnext. Открываем Cpp файл. В нём меняем надпись на свою. В данном случае на as006105.  

Собираем. В случае неудачи, открываем PLCnext-howto-master/HowTo build program Hello PLCnext/Hello-PLCnext/CmakeCashe, и находим там строчку "CMAKE_MAKE_PROGRAM:FILEPATH", пишем туда свой путь к ninja. По-умолчанию должен установиться путь C:/Program Files (x86)/MicrosoftVisualStudio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/ninja.exe 

Пересобиаем проект.   
Скачиваем программы WinSCP, PuTTy.   
Далее заходим в панель управления/Сеть и Интернет/Центр управления сетями и общим доступом, и выбираем там сеть Ethernet, прописываем ей ip 192.168.1.1, маску подсети 255.255.255.0
В PuTTy пишем ip 192.168.1.10, контроллёр подключается.
В WinSCP пишем тот же ip, имя пользователя указывается "admin", а пароль есть на контроллере.   
После входа в файловую систему контроллера перемещаем наш файл hello_PLCnext на него и даём все расширения и права во избежание ошибки permission denied.   
Через терминал контроллера запускаем файл, прописав туда ./hello_PLCnext. При правильном выполнении предыдущих действий в результате увидим в терминале контроллера строку "Hello PLCnext from as006112".   

![](../../images/Lab3Result.jpg)

![](../../images/Lab3Photo.jpg)

<p> <strong> Вывод:</strong> в ходе данной лабораторной работы запустили проект на контроллере AXCF 2152.
