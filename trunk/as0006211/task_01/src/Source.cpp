#include <iostream>
#include <cmath>
#define N 16		// kolichestvo izmeneniy temperaturi

float linear_transformation(float y[N], float u, float a, float b) {
	float new_temperature[N];

	for (int i = 1; i < N; i++) {
		y[i] = a * y[i - 1] + b * u;
		new_temperature[i] = y[i];
	}
<<<<<<< HEAD
	return new_temperature[N];
=======
	return new_temperature[N-1];
>>>>>>> 00dc17073cbb6095d105fde5dbd897788f19a933
}

float nonlinear_transformation(float y[N], float u, float a, float b, float c, float d) {
	float new_temperature[N];
	y[1] = a * y[0] + b * u;
	new_temperature[1] = y[1];

	for (int i = 2; i < N; i++) {
		y[i] = a * y[i - 1] - b * pow(y[i-2],2) + c * u + d * sin(u);
		new_temperature[i] = y[i];
	}
<<<<<<< HEAD
	return new_temperature[N];
=======
	return new_temperature[N-1];
>>>>>>> 00dc17073cbb6095d105fde5dbd897788f19a933
}

int choose_transformation() {


	float temperature[N];
	float warm;
<<<<<<< HEAD
	float a = 0.1;		//	
	float b = 0.01;	//const
	float c = 0.3;		//
	float d = 0.2;		//
=======
	cosnt float a = 0.1;		//	
	cosnt float b = 0.01;		//const
	cosnt float c = 0.03;		//
	cosnt float d = 0.02;		//
>>>>>>> 00dc17073cbb6095d105fde5dbd897788f19a933
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

