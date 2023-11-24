<p align="center">MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS</p>
<p align="center">EDUCATIONAL INSTITUTION</p>
<p align="center">«BREST STATE TECHNICAL UNIVERSITY»</p>       
<p align="center">Department of IIT</p>
<br><br><br><br>
<p align="center">Laboratory work №.3</p>
<br><br><br>
<p align="right">Completed by the 3rd year student of</p> 
<p align="right">the Faculty of Electronic Information Systems</p>
<p align="right">the group AC-61 Dzibuk A.V.</p>
<p align="right">Checked by Ivanuk D.S.</p>
<br><br><br>
<p align="center">Brest 2023</p>

---

## Task 3. Work with AXC F 2152 controller:

Using Visual Code to create a test project "Hello PLCnext from AS06104!", build it and demonstrate performance on the test controller.

### Steps to run:
1. To clone "savushkin-r-d/PLCnext-howto" repository on a computer and build the executable file "hello_PLCnext" in Visual Code using CMake.
<p align="center"><img style='border:2px solid #000000'src="images/executable_file.png"/>

2. To connect to the controller via LAN-cable, after we set up IPV-4 connection. In the properties of this connection we need to use "192.168.1.1" ip-address and "255.255.255.0" mask.
<p align="center"><img style='border:2px solid #000000'src="images/network_configuration.png"/>

3. For checking connection we use "ping 192.168.1.10" command in the command line, where "192.168.1.10" is controller's ip-address. If packets are not lost, then the connection is set correctly.
<p align="center"><img style='border:2px solid #000000'src="images/ping_controller.png"/>

4. Install 2 programs on a computer: PuTTY and WinSCP.

5. Using PuTTY we connect to the controller, entering controller's ip-address, login - "admin" and password - "785*****". 
<p align="center"><img style='border:2px solid #000000'src="images/putty_connection.png"/>
<p align="center"><img style='border:2px solid #000000'src="images/putty.png"/>

6. To transfer the executable file to the root of the controller using WinSCP program. We also enter the ip-address, the login and the password of the controller.
<p align="center"><img style='border:2px solid #000000'src="images/winscp_connection.png"/>
<p align="center"><img style='border:2px solid #000000'src="images/winscp.png"/>

7. To change the access rights to start the executable file.
<p align="center"><img style='border:2px solid #000000'src="images/access_rights.png"/>

8. To run executable file.
<p align="center"><img style='border:2px solid #000000'src="images/output.png"/>
<p align="center"><img style='border:2px solid #000000'src="images/laptop.jpg"/>
