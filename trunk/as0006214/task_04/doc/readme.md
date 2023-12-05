<p align="center"><strong>Educational institution</strong></p><br>
<p align="center"><strong>“Brest State Technical University”</strong></p><br>
<p align="center"><strong>IIT Department</strong></p><br>
<br><br><br><br><br>
<p align="center"><strong>Laboratory work No. 4</strong></p><br>
<p align="center"><strong>In the discipline “Theory and methods of automatic control”</strong></p><br>
<p align="center"><strong>Topic: “Working with the AXC F 2152 controller”</strong></p><br>
<br><br><br><br><br>
<p align="right"><strong>Made by:</strong></p><br>
<p align="right">3rd year student</p><br>
<p align="right">AS-62 groups</p><br>
<p align="right">Kulick A.D.</p>
<br><br><br>
<p align="right"><strong>Checked:</strong></p><br>
<p align="right">Senior Lecturer</p><br>
<p align="right">Ivanyuk D.S.</p><br>
<br><br><br><br><br>
<p align="center">Brest 2023</p><br>

---
<p><strong>Task</strong><p>
<li><p>1. Read general information about the **PLCnext** platform [here](https://www.plcnext.help/te/About/Home.htm).</li></p>

<li><p>2. Study the project [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).</li></p>

<li><p>3. Using **Visual Studio** collect project data and demonstrate performance on a test controller.</li></p>

<li><p>4. Write a report on the work performed in .md format (readme.md) and use a pull request to place it in the following directory: trunk\as000xxyy\task_04\doc.</li></p>
<p> <strong>Aim: </strong>using <em>Visual Studio</em> assemble this project and demonstrate its functionality on a test controller.</p> 
<br>
<p> <strong>Solution:</strong> </p>
<br>
<ul>
<br>
<li>According to the assignment of laboratory work No. 4, we clone the repository [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).</li>
<br>
<li><p>Open total repo in the visual studio. Thus we get a project based on CMake.</p></li>
<br>
<li><p>Using Visual Studio We are assemble this project with CMake assembly tool.</p></li>
<br>
![](images/sborkavvizle.jpg)
<br><br>
<li><p>Next we connect to the test controller AXC F 2152 in the laboratory.</p></li>
<br>
![](images/kontroller.jpg)
<br><br>
![](images/win_cp.jpg)
<br><br>
<li><p>We go to the folder with the project, having previously moved it to the controller, and launch our program:</p></li>
<br>
![](images/repo.jpg)
<br><br>
<li><p>For the resulting assembly file hello_PLCnext we set the access rights</p></li>
<br>
![](images/prava_ptusi.jpg)
<br><br>
<li><p>Now using folowing command, we get the result: </p></li>
<br>
./ptusa_main  main.plua  sys_path  ./sys/
<br>
<li><p>We get the following output from our program: </p></li>
<br>
</ul>
<br>
![](images/result.jpg)
<br><br>
![](images/photo_of_result.jpg)
<br><br>
<p> Conclusion: During the course of this laboratory work, we gained valuable experience working with Visual Studio and the AXC F 2152 controller, which is an important step in acquiring programming skills and working with automated systems. Additionally, it is worth noting that such practical exercises not only reinforce theoretical knowledge but also develop the ability to solve real technical problems, which is a key aspect of engineering activities.</p>
<br>
<p>The use of the AXC F 2152 controller opens up wide possibilities for creating flexible and scalable automation systems. Thanks to its high performance and multifunctionality, we can successfully implement complex projects in the field of industrial automation. The new skills acquired in working with this controller can be applied in various projects, ranging from simple monitoring and control tasks to complex systems that require integration with other devices and services.
<br>
<p>This laboratory work required significantly less time to complete compared to the previous one, taking approximately an hour or two. This laboratory work was carried out by a team of students as006214, as006219, as006217.</p>
<br>
<p>this laboratory work helped us learn to work in a team and develop more soft skills.</p><br>
![](images/team.jpg)
<br><br>