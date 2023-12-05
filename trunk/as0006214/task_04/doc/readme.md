<p align="center"><strong>Institución educativa</strong></p><br>
<p align="center"><strong>“Universidad Técnica Estatal de Brest”</strong></p><br>
<p align="center"><strong>Departamento de IIT</strong></p><br>
<br><br><br><br><br>
<p align="center"><strong>Trabajo de laboratorio No. 4</strong></p><br>
<p align="center"><strong>En la disciplina " Teoría y métodos de control automático”</strong></p><br>
<p align="center"><strong>Tema: "Trabajar con el controlador AXC F 2152"</strong></p><br>
<br><br><br><br><br>
<p align="right"><strong>Made by:</strong></p><br>
<p align="right">estudiante de 3er año</p><br>
<p align="right">AS-62 groups</p><br>
<p align="right">Kulick A.D.</p>
<br><br><br>
<p align="right"><strong>Checked:</strong></p><br>
<p align="right">Profesor Titular</p><br>
<p align="right">Ivanyuk D.S.</p><br>
<br><br><br><br><br>
<p align="center">Brest 2023</p><br>

---
<p><strong>Task</strong><p>
<li><p>1. Read general information about the **PLCnext** platform [here](https://www.plcnext.help/te/About/Home.htm).</li></p>

<li><p> 2. Estudiar el proyecto [ptusa_main] (https://github.com/savushkin-r-d/ptusa_main).</li></p> 
<li><p>3. Usando** Visual Studio * * recopile datos del proyecto y demuestre el rendimiento en un controlador de prueba.</li></p> 
<li><p>4. Redactar un informe sobre el trabajo realizado en formato. md (readme.md) y use una solicitud de extracción para colocarla en el siguiente directorio: trunk \ as000xxyy \ task_04.</li></p>
<p><strong>Objetivo: </strong>usando<em>Visual Studio </em> ensamble este proyecto y demuestre su funcionalidad en un controlador de prueba.</p>
<br>
<p> <strong>Solución:</strong> </p>
<br>
<ul>
<br>
<li>De acuerdo con la asignación del trabajo de laboratorio No. 4, clonamos el repositorio [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).</li>
<br>
<li><p>Abra el repositorio total en visual Studio. Así obtenemos un proyecto basado en CMake.</p></li>
<br>
<li><p>Usando Visual Studio, ensamblamos este proyecto con la herramienta de ensamblaje CMake.</p></li>
<br>
![](images/sborkavvizle.jpg)
<br><br>
<li><p>A continuación, nos conectamos al controlador de prueba AXC F 2152 en el laboratorio.</p></li>
<br>
![](images/kontroller.jpg)
<br><br>
![](images/win_cp.jpg)
<br><br>
<li><p>Vamos a la carpeta con el proyecto, habiéndolo movido previamente al controlador, y lanzamos nuestro programa:</p></li>
<br>
![](images/repo.jpg)
<br><br>
<li><p>para el archivo ensamblado resultante hello_PLCnext establecemos los derechos de acceso.</p></li>
<br>
![](images/prava_ptusi.jpg)
<br><br>
<li><p>Ahora usando el siguiente comando, obtenemos el resultado:</p></li>
<br>
./ptusa_main  main.plua  sys_path  ./sys/
<br>
<li><p>Obtenemos el siguiente resultado de nuestro programa:</p></li>
<br>
</ul>
<br>
![](images/result.jpg)
<br><br>
![](images/photo_of_result.jpg)
<br><br>
<p>Conclusión: Durante el transcurso de este trabajo de laboratorio, adquirimos una valiosa experiencia trabajando con Visual Studio y el controlador AXC F 2152, que es un paso importante para adquirir habilidades de programación y trabajar con sistemas automatizados. Además, vale la pena señalar que tales ejercicios prácticos no solo refuerzan los conocimientos teóricos, sino que también desarrollan la capacidad de resolver problemas técnicos reales, lo cual es un aspecto clave de las actividades de ingeniería.</p>
<br>
<p>El uso del controlador AXC F 2152 abre amplias posibilidades para crear sistemas de automatización flexibles y escalables. Gracias a su alto rendimiento y multifuncionalidad, podemos implementar con éxito proyectos complejos en el campo de la automatización industrial. Las nuevas habilidades adquiridas al trabajar con este controlador se pueden aplicar en diversos proyectos, que van desde simples tareas de monitoreo y control hasta sistemas complejos que requieren integración con otros dispositivos y servicios.</p>
<br>
<p>Este trabajo de laboratorio requirió significativamente menos tiempo para completarse en comparación con el anterior, y tomó aproximadamente una o dos horas. Este trabajo de laboratorio fue realizado por un equipo de estudiantes as006214, as006219, as006217.</p>
<br>
<p>este trabajo de laboratorio nos ayudó a aprender a trabajar en equipo y desarrollar más habilidades blandas.</p><br>
![](images/team.jpg)
<br><br>
