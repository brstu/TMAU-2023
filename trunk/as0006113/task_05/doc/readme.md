<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br>
<p align="center">Лабораторная работа №5</p>
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

<p> <strong>Цель:</strong> собрать тестовый проeкт ptusa_main, изменить main.plau и продемонстрировать работоспособность на тестовом контроллере.</p>

<p> <strong>Ход работы (совместно с Поцелуйко и Дзибуком):</strong> </p>
<p>Для решения поставленной задачи, для начала необходимо собрать файл <em>ptusa_main</em> в Visual Studio. Порядок сборки и подключения указан в лабораторной работе [№3](https://github.com/AlexPavlucik/TMAU-2023/tree/main/trunk/as0006113).  </p>

<p>Были внесены изменения в main.plau. Был изменен порядок свечения лапмочек.</p>

``` bash
function user_init()
    local delta = 200

    A5HL1_info.start_time = get_millisec()
    A5HL3_info.start_time = A5HL1_info.start_time - delta
    A5HL5_info.start_time = A5HL3_info.start_time - delta
    A5HL7_info.start_time = A5HL5_info.start_time - delta
    A5HL2_info.start_time = A5HL7_info.start_time - delta
    A5HL4_info.start_time = A5HL2_info.start_time - delta
    A5HL6_info.start_time = A5HL4_info.start_time - delta
    A5HL8_info.start_time = A5HL6_info.start_time - delta
end
```

<p>Работа контроллера прдставлена на площадке ютуб </p>

``` bash
https://youtube.com/shorts/dQ2PyLuyWYQ?si=rofiJEyTblShCQ1V
```
