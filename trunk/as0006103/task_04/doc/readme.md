<p align="center">Ministry of Education of the Republic of Belarus</p>
<p align="center">Educational institution</p>
<p align="center">"Brest State Technical University"</p>
<p align="center">Department of IIT</p>
<br><br><br><br><br><br>
<p align="center"><strong>Laboratory work No. 4</strong></p>
<p align="center"><strong>By discipline</strong> TMAU</p>
<p align="center"><strong>Subject:</strong> "Working with the AXCF 2152 controller"</p>
<br><br><br><br><br><br>
<p align="right"><strong>Completed </strong>:</p>
<p align="right">3rd year student</p>
<p align="right">AC-61 groups</p>
<p align="right">Voloshko M.V.</p>
<p align="right"><strong>Checked:</strong></p>
<p align="right">Ivanyuk D. S.</p>
<br><br><br><br><br>
<p align="center"><strong>Brest 2023</strong></p>

---
***Goal:***
Learn how to build and run a project on an AXCF 2152 controller.
<br><br><br>
***Task***:
`` bash
1) Read the general information about the PLCnext platform here.
2) Explore the ptusa_main project.
3) Using Visual Studio, collect project data and demonstrate performance on a test controller.
4)Write a report on the completed work in .md format (readme.md ) and use pull request to place it in the following directory: trunk\as000xxyy\task_04\doc.
<br><br><br>
```

***The sequence of actions:***
<br>
Cloning the repository <br>

``` bash
[ptusa_main](https://github.com/savushkin-r-d/ptusa_main).
```
<p>Open this repository in <strong>Visual Studio</strong>, create a project based on <strong>CMake</strong>.</p>
<p>Using <strong>Visual Studio</strong>, we compile the project.</p> 
<p>We connect to the controller, according to the same principle as in the 3rd laboratory work: </p>

[task_03](../../task_03/doc/readme.md).
<br>

![](images/expl.png)
<br>

Go to the folder with the project and run the program:<br>
``` bash

./ptusa_main  main.plua  sys_path  ./sys/

```

<br>
We get the result in the form of the following output in the console: <br>

![](../../images/laba4.png)


<br><br>
<strong><em>Conclusion:</em></strong>
<p>During the laboratory work, we learned how to build a project for the AXCF 2152 controller and run it. </p>

![](../../images/we.png)