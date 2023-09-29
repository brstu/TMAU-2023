#include <iostream>
#include <cmath>

using namespace std;

#define nm 16		

double nonlinear(double y[nm], double u, double a, double b, double c, double d) {
	double new_gradus[nm];
	y[1] = b * u + a * y[0] ;
	new_gradus[1] = y[1];
	for (int i = 2; i < nm; i++) {
		y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * u + d * sin(u) ;
		new_gradus[i] = y[i];
	}
	return new_gradus[nm - 1];
}

double linear(double y[nm], double u, double a, double b) {
	double new_gradus[nm];
	for (int i = 1; i < nm; i++) {
		y[i] = b * u + a * y[i - 1];
		new_gradus[i] = y[i];
	}
	return new_gradus[nm - 1];
}

int main() {

	double temperature[nm];
	double choosen_warm;
	int temp;
	cout << "choose : \n 0 - linear \n 1,2,3,4,5,6,7,8,9 - nonlinear" << endl;
	cin >> temp;
	cout << "enter temperature " << endl;
	cin >> temperature[0];
	cout << "enter choosen_warm " << endl;
	cin >> choosen_warm;
	const double z = 0.1;
	const double x = 0.01;
	const double c = 0.03;
	const double v = 0.02;

	if (temp == 0) {
		linear(temperature, choosen_warm, z, x);
		for (int i = 0; i < nm; i++) {
			cout << "y[" << i << "]=" << temperature[i] << endl;
		}
	}
	else {
		nonlinear(temperature, choosen_warm, z, x, c, v);
		for (int i = 0; i < nm; i++) {
			cout << "y[" << i << "]=" << temperature[i] << endl;
		}
	}
	system("pause");
	return 0;
}
