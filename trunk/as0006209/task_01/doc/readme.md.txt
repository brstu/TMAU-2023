<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-62</p>
<p align="right">Кравцов Г.С.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---

**Задание**:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

**Код решения:**

``` C++
#include <iostream>
#include <cmath>
#define N 16		// kolichestvo izmeneniy temperaturi

float linear_transformation(float y[N], float u, float a, float b) {
	float new_temperature[N];

	for (int i = 1; i < N; i++) {
		y[i] = a * y[i - 1] + b * u;
		new_temperature[i] = y[i];
	}
	return new_temperature[N];
}

float nonlinear_transformation(float y[N], float u, float a, float b, float c, float d) {
	float new_temperature[N];
	y[1] = a * y[0] + b * u;
	new_temperature[1] = y[1];

	for (int i = 2; i < N; i++) {
		y[i] = a * y[i - 1] - b * pow(y[i-2],2) + c * u + d * sin(u);
		new_temperature[i] = y[i];
	}
	return new_temperature[N];
}

int choose_transformation() {


	float temperature[N];
	float warm;
	float a = 0.1;		//	
	float b = 0.01;	//const
	float c = 0.3;		//
	float d = 0.2;		//
	int temp;

	std::cout << "choose type of transformation: \n 1 - linear \n 2 - nonlinear" << std::endl;
	std::cin >> temp;
	std::cout << "enter temperature " << std::endl;
	std::cin >> temperature[0];
	std::cout << "enter warm " << std::endl;
	std::cin >> warm;
	std::cout << "\n";

	
	if (temp == 1){
		linear_transformation( temperature, warm, a, b);
		for (int i = 0; i < N; i++) {
			std::cout << "y["<< i <<"]=" << temperature[i] << std::endl;
		}
	}
	else {
		nonlinear_transformation(temperature, warm, a, b, c, d);
		for (int i = 0; i < N; i++) {
			std::cout << "y[" << i << "]=" << temperature[i] << std::endl;
		}
	}

	return 0;
}


int main() {
	choose_transformation();

	system("pause");
	return 0;
}


```

Пример вывода программы:

``` bash
choose type of transformation:
 1 - linear
 2 - nonlinear
1
enter temperature
45
enter warm
13

y[0]=45
y[1]=4.63
y[2]=0.593
y[3]=0.1893
y[4]=0.14893
y[5]=0.144893
y[6]=0.144489
y[7]=0.144449
y[8]=0.144445
y[9]=0.144444
y[10]=0.144444
y[11]=0.144444
y[12]=0.144444
y[13]=0.144444
y[14]=0.144444
y[15]=0.144444
Press any key to continue . . .

choose type of transformation:
 1 - linear
 2 - nonlinear
2
enter temperature
45
enter warm
13

y[0]=45
y[1]=4.63
y[2]=-15.803
y[3]=2.18937
y[4]=1.70563
y[5]=4.10666
y[6]=4.36561
y[7]=4.25195
y[8]=4.21864
y[9]=4.22511
y[10]=4.22857
y[11]=4.22838
y[12]=4.22806
y[13]=4.22805
y[14]=4.22807
y[15]=4.22808
Press any key to continue . . .


```