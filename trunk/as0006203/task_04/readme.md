<p align="center"><strong>Министерство образования Республики беларусь</strong></p>
<p align="center"><strong>Учреждение образования</strong></p>
<p align="center"><stong>БрГТУ</stong></p>
<p align="center"><strong>Кафедра интеллектуальных информационных технологий</strong></p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №4</strong></p>
<p align="center"><strong>По дисциплине</strong> “ТиМАУ”</p>
<p align="center"><strong>Тема:</strong> “Работа с контроллером”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Выполнил: </strong>:</p>
<p align="right">Студент 3-го курса</p>
<p align="right">Группы АС-62</p>
<p align="right">Гомон М.Д.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br><br><br>
<p align="center"><strong>Brest 2023</strong></p>

---
<p> <strong> Цель </strong> Используя Visual Studio собрать проект ptusa_main и продемонтрировать работоспособность на котроллере </p>

Задание: [#4] (../../../../tasks/task_04/readme.md) 

<p> <strong> Решение </strong> </p>


<p>Копируем репозиторий проекта используя команду <em> git clone --recurse-submodules https://github.com/savushkin-r-d/ptusa_main.git </em> </p>
<p>Запускаем репозиторий в <em> Visual Studio </em> и после этого собираем проект при помощи Cmake. При сборке возникла следующая ошибка <em>c:/CLI/sdks/AXCF2152/2022_0/sysroots/x86_64-w64-mingw32/usr/bin/arm-pxc-linux-gnueabi/arm-pxc-linux-gnueabi-gcc.exe</em> Проблема решается обновлением  SDK до версии 2023.6.0.43 </p> 
<p>Выбираем сборку <em>AXCF2152-2023 LTS</em></p>

![](images/assembly_selections.jpg)

<p>Собираем проект</p>

![](images/project_assembly.jpg)

<p>В результате получаем Каталог <em>AXCF2152_2022_0 </em> в котором хранится файл <em>ptusa_main</em> </p>

![](images/build_result.jpg)

<p>Далее подключаемся к контроллеру, проверяем подключение, авторизируемся в <em>Putty Configuration</em> и <em>WinSCP</em> создаем каталог <em>main</em> в котором будут находиться нужные файлы для запуска программы </p>

![](images/files.jpg)
![](images/files_for_start_project.jpg)

<p>В <em>Putty</em> вводим  команды <em>./ptusa_main  main.plua  sys_path  ./sys/</em> и в результате получаем: </p>

![](images/output.jpg)
![](images/photo_output.jpg)

<p><strong>Вывод </strong>Используя Visual Studio собрали проект и продемонстрировали работоспособность на контроллере. </p>
