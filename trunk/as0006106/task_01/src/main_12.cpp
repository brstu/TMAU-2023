#include <iostream>
#include <cmath>
using namespace std;

class TemperatureController
{
	const double A = 1.2;
	const double B = 0.9;
	const double C = 1.7;
	const double D = 1;
	double temperature;
	double warm;


public:

	TemperatureController(double temperature, double warm) : temperature(temperature),warm(warm) {}
	double LinearSimulation() const {
		double y = A * this->temperature + B * this->warm;
		return y;
	}
	double NonLinearSimulation() const {
		double start_temperature = 1;
		double start_warm = 1;
		double simulation = A * this->temperature - B * pow(start_temperature, 2) + C * this->warm + D * sin(start_warm);
		return simulation;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	double temperature;
	double warm;
	cout << "Введите температуру:"<<endl;
	cin >> temperature;
	cout << "Введите количество тепла:" << endl;
	cin >> warm;
	TemperatureController tmp(temperature, warm);
	cout << "Линейная модель y(t) = " << tmp.LinearSimulation()<<endl;
	cout << "Нелинейная модель y(t) = " << tmp.NonLinearSimulation()<<endl;
	system("pause");
	return 0;
}

