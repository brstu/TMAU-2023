<p align="center"> Ìèíèñòåðñòâî îáðàçîâàíèÿ Ðåñïóáëèêè Áåëàðóñü</p>
<p align="center">Ó÷ðåæäåíèå îáðàçîâàíèÿ</p>
<p align="center">“Áðåñòñêèé Ãîñóäàðñòâåííûé òåõíè÷åñêèé óíèâåðñèòåò”</p>
<p align="center">Êàôåäðà ÈÈÒ</p>
<br><br><br><br><br><br><br>
<p align="center">Ëàáîðàòîðíàÿ ðàáîòà ¹1</p>
<p align="center">Ïî äèñöèïëèíå “Òåîðèÿ è ìåòîäû àâòîìàòè÷åñêîãî óïðàâëåíèÿ”</p>
<p align="center">Òåìà: “Ìîäåëèðîâàíèÿ òåìïåðàòóðû îáúåêòà”</p>
<br><br><br><br><br>
<p align="right">Âûïîëíèë:</p>
<p align="right">Ñòóäåíò 3 êóðñà</p>
<p align="right">Ãðóïïû ÀÑ-62</p>
<p align="right">Ãîìîí Ì. Ä.</p>
<p align="right">Ïðîâåðèë:</p>
<p align="right">Èâàíþê Ä. Ñ.</p>
<br><br><br><br><br>
<p align="center">Áðåñò 2023</p>

---

**Çàäàíèå**:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**Ñ++**), which simulates this object temperature.

**Êîä ðåøåíèÿ:**

``` C++
#include <iostream>
#include <cmath>

int n = 16;

double linearModel (double y[16], double u, double a, double b){
    double newTemp [n];

    for (int i = 1; i < n; i++)
    {
        y[i] = a * y[i - 1] + b * u;
        newTemp[i] = y[i]; 
    }
     
    // Print the results for linear model
    std::cout << "For linear model:\n";
    for (int i = 1; i < n; i++) std::cout << "y["<< i <<"] = " << newTemp[i] << " \n";
    
    return 0;
}

double nonLinearModel(double y[16], double u, double a, double b, double c, double d){
    double newTemp2 [n];

    for (int i = 2; i < n; i++)
    {
        y[i] = a * y[i - 1] - b * y[i - 2] + c * u + d * sin(u);
        newTemp2[i] = y[i];
    }
    
    // Print the results for linear model
    std::cout << "For nonlinear model:\n";
    for (int i = 2; i < n; i++) std::cout << "y["<< i <<"] = " << newTemp2[i] << " \n";

    return 0;
}

int main(){
    double a = 1.2;
    double b = -0.4;
    double c = 0.6;
    double d = -0.2;
    double y[16];
    double u;
    


    std::cout << "input temperature"; 
    std::cin >> y[0];
    std::cout << "input warm"; 
    std::cin >> u;

    linearModel (y, u, a, b);
    nonLinearModel (y, u, a, b, c, d);


}
```

Ïðèìåð âûâîäà ïðîãðàììû:

``` bash
input temperature 12
input warm 12
For linear model:
y[1] = 9.6
y[2] = 6.72
y[3] = 3.264
y[4] = -0.8832
y[5] = -5.85984
y[6] = -11.8318
y[7] = -18.9982
y[8] = -27.5978
y[9] = -37.9174
y[10] = -50.3008
y[11] = -65.161
y[12] = -82.9932
y[13] = -104.392
y[14] = -130.07
y[15] = -160.884

For nonlinear model:
y[2] = 23.6273
y[3] = 39.5001
y[4] = 64.1584
y[5] = 100.097
y[6] = 153.088
y[7] = 231.051
y[8] = 345.804
y[9] = 514.692
y[10] = 763.26
y[11] = 1129.1
y[12] = 1667.53
y[13] = 2459.98
y[14] = 3626.29
y[15] = 5342.85
```
