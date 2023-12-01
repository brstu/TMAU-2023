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
<p align="right">Леонович А.А.</p>
<p align="right">Проверил:</p>
<p align="right">Старший преподаватель</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2023</p>

---

### Цель работы: собрать его тестовый проект ptusa_main и продемонстрировать работоспособность на тестовом контроллере.</p>

<p> <strong>Решение.:</strong> </p>

<p>Чтобы выполнить поставленную задачу, сначала нужно скомпилировать файл <em>ptusa_main</em> в Visual Studio. Для компиляции файла сначала требуется клонировать репозиторий,, что достигается с помощью следующей команды:</p>

 ``` bash
git clone --recurse-submodules https://github.com/savushkin-r-d/ptusa_main.git 
```

<p>Далее следуя инструкциям из репозитория собираем проект..</p>

``` bash
https://github.com/savushkin-r-d/ptusa_main/tree/master/russian_readme#%D0%BA%D0%B0%D0%BA-%D1%81%D0%BE%D0%B1%D1%80%D0%B0%D1%82%D1%8C-%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82
```

<p>Затем мы подключаемся к контроллеру, следуя тем же шагам, что и в <em>3-й лабораторной работе:</em> </p>

[task_03](../../task_03/doc/readme.md).

<p>Переходим в папку с проектом и запускаем нашу программу:</p>

``` bash

./ptusa_main  main.plua  sys_path  ./sys/

```

<p>Получаем результат в виде следущего вывода в консоли: </p>

![](images/console.png)

![](images/main-admin.png)

![](images/notebookscreen.png)

![](images/screenshot_workpage.png)

![](images/together.png)

 Вывод: в процессе выполнения этой лабораторной работы были изучены новые возможности в среде Visual Studio, успешно выполнена сборка проекта и получены дополнительные навыки работы с тестовым контроллером AXC F 2152.