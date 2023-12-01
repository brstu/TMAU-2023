<p align="center">MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS</p>
<p align="center">EDUCATIONAL INSTITUTION</p>
<p align="center">«BREST STATE TECHNICAL UNIVERSITY»</p>       
<p align="center">Department of IIT</p>
<br><br><br><br>
<p align="center">Laboratory work №.3</p>
<br><br><br>
<p align="right">Completed by the 3rd year student of</p> 
<p align="right">the Faculty of Electronic Information Systems</p>
<p align="right">the group AC-62 Kapuza V.V.</p>
<p align="right">Checked by Ivanuk D.S.</p>
<br><br><br>
<p align="center">Brest 2023</p>

---

## Task 3. Work with AXC F 2152 controller:

Using Visual Code to create a test project "PLCnext-howto from AS06210!",performance on the test controller.

### Steps to run:
1. To clone "savushkin-r-d/PLCnext-howto" repository on a computer and build the file "LICENSE " in Visual Code using CMake.
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_8.png"/>

2. To connect to the controller, after we set up IPV-4 connection. In the properties of this connection we need to use "192.168.1.1" ip-address and "255.255.255.0" mask.
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_1.png"/>

3. For checking connection we use "ping 192.168.1.1" command in the command line. If packets are not dropped, then the connection is configured properly.
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_2.png"/>

4. Download 2 applications on a computer: PuTTY and WinSCP.

5. Employing PuTTY, we establish a connection to the controller by providing the controller's IP address, "admin" as the login, and "*****" as the password. 
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_3.png"/>


6. To transfer the executable file to the root directory of the controller, utilize the WinSCP application. Additionally, provide the controller's IP address, login credentials, and password. 
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_4.png"/>


7. Modify the permissions to execute the file.
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_5.png"/>

8. Execute the file.
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_6.png"/>
<p align="center"><img style='border:2px solid #000000'src="scrin/Screenshot_7.png"/>
