#include "Lab1.h"
#include <iostream>
#include <cmath>

using namespace std;

#define Numer 16		



float nonlinear(float y[Numer], float u, float a, float b, float c, float d) {
	float new_gradus[Numer];
	y[1] = a * y[0] + b * u;
	new_gradus[1] = y[1];
	for (int i = 2; i < Numer; i++) {
		y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * u + d * sin(u);
		new_gradus[i] = y[i];
	}
	return new_gradus[Numer - 1];
}

float linear(float y[Numer], float u, float a, float b) {
	float new_gradus[Numer];
	for (int i = 1; i < Numer; i++) {
		y[i] = a * y[i - 1] + b * u;
		new_gradus[i] = y[i];
	}
	return new_gradus[Numer - 1];
}

int transformation() {
	float temperature[Numer];
	float choosen_warm;
	const float z = 0.1;		
	const float x = 0.01;		
	const float c = 0.03;		
	const float v = 0.02;		
	int temp;

	cout << "choose : \n 1 - linear \n 2 - nonlinear" << endl;
	cin >> temp;
	cout << "enter temperature " <<endl;
	cin >> temperature[0];
	cout << "enter choosen_warm " <<endl;
	cin >> choosen_warm;
	cout << "\n";


	if (temp == 1) {
		linear(temperature, choosen_warm, z, x);
		for (int i = 0; i < Numer; i++) {
			cout << "y[" << i << "]=" << temperature[i] << endl;
		}
	}
	else {
		nonlinear(temperature, choosen_warm, z, x, c, v);
		for (int i = 0; i < Numer; i++) {
			cout << "y[" << i << "]=" << temperature[i] << endl;
		}
	}

	return 0;
}


int main() {

	transformation();
	system("pause");
	return 0;
}
