<p align="center">MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS</p>
<p align="center">EDUCATIONAL INSTITUTION</p>
<p align="center">«BREST STATE TECHNICAL UNIVERSITY»</p>       
<p align="center">Department of IIT</p>
<br><br><br><br>
<p align="center">Laboratory work №.5</p>
<br><br><br>
<p align="right">Completed by the 3rd year student of</p> 
<p align="right">the Faculty of Electronic Information Systems</p>
<p align="right">the group AC-61 Dzibuk A.V.</p>
<p align="right">Checked by Ivanuk D.S.</p>
<br><br><br>
<p align="center">Brest 2023</p>

---

## Task 5. Work with AXC F 2152 controller:

Link to the condition: [task_05](https://github.com/brstu/TMAU-2023/blob/main/tasks/task_05/readme.md).

### Work progress:

It was added the following code in "user_eval" function of main.plua file:
```bash
if A2DI1:get_state() == 1 then HLA1:normal_blink_green()
else HLA1:off() end

if A2DI2:get_state() == 1 then HLA1:turn_on_yellow()
else HLA1:turn_off_yellow() end

if A2DI3:get_state() == 1 then HLA1:turn_on_red()
else HLA1:turn_off_red() end
```

## Results
<p align="left"><img style='border:2px solid #000000'src="blink_hla1.gif"/>