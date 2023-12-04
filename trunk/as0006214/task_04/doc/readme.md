<p align="center">Ministry of Education of the Republic of Belarus</p>
<p align="center">Educational institution</p>
<p align="center">“Brest State Technical University”</p>
<p align="center">IIT Department</p>
<br><br><br>
<p align="center">Laboratory work No. 4</p>
<p align="center">In the discipline “Theory and methods of automatic control”</p>
<p align="center">Topic: “Working with the AXC F 2152 controller”</p>
<br><br><br>
<p align="right"><strong>Completed by:</strong></p>
<p align="right">3rd year student</p>
<p align="right">AS-62 groups</p>
<p align="right">Kulick A.D.</p>
<br>
<p align="right"><strong>Checked:</strong></p>
<p align="right">Senior Lecturer</p>
<p align="right">Ivanyuk D.S.</p>
<br><br><br>
<p align="center">Brest 2023</p>

---
Task: [#4](../../../../tasks/task_04/readme.md).

<p> <strong>Aim: </strong>using <em>Visual Studio</em> assemble this project and demonstrate its functionality on a test controller.</p> 

<p> <strong>Solution:</strong> </p>

<ul>

<li>According to the assignment of laboratory work No. 4, we clone the repository [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).</li>

<li><p>Open total repo in the visual studio. Thus we get a project based on CMake.</p></li>

<li><p>Using Visual Studio We are assemble this project with CMake assembly tool.</p></li>

![](images/sborkavvizle.jpg)

<li><p>Next we connect to the test controller AXC F 2152 in the laboratory.</p></li>

![](images/kontroller.jpg)

![](images/win_cp.jpg)

<li><p>We go to the folder with the project, having previously moved it to the controller, and launch our program:</p></li>

![](images/repo.jpg)

<li><p>For the resulting assembly file hello_PLCnext we set the access rights</p></li>

![](images/prava_ptusi.jpg)

<li><p>Now using folowing command, we get the result: </p></li>
``` bash

./ptusa_main  main.plua  sys_path  ./sys/

```

<li><p>We get the following output from our program: </p></li>

</ul>

![](images/result.jpg)

![](images/photo_of_result.jpg)

<p> Conclusion: During the course of this laboratory work, we gained valuable experience working with Visual Studio and the AXC F 2152 controller, which is an important step in acquiring programming skills and working with automated systems. Additionally, it is worth noting that such practical exercises not only reinforce theoretical knowledge but also develop the ability to solve real technical problems, which is a key aspect of engineering activities.</p>

<p>The use of the AXC F 2152 controller opens up wide possibilities for creating flexible and scalable automation systems. Thanks to its high performance and multifunctionality, we can successfully implement complex projects in the field of industrial automation. The new skills acquired in working with this controller can be applied in various projects, ranging from simple monitoring and control tasks to complex systems that require integration with other devices and services.

<p>This laboratory work required significantly less time to complete compared to the previous one, taking approximately an hour or two. This laboratory work was carried out by a team of students as006214, as006219, as006217.</p>

![](images/team.jpg)