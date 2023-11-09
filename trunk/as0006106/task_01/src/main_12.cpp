#include <iostream>
#include <cmath>
using namespace std;

class TemperatureController
{
	const double A = 1.2;
	const double B = 0.9;
	const double C = 1.7;
	const double D = 1;
	double time;
	double temperature;
	double warm;



public:
	TemperatureController(double time=0, double temperature=0, double warm=0: time(time),temperature(temperature),warm(warm)) {
	}
	double LinearSimulation() const {
		double y = A * this->temperature + B * this->warm;
		return y;
	}
	double NonLinearSimulation() const {
		double start_temperature = 1, start_warm = 1;
		double simulation = A * this->temperature - B * pow(start_temperature, 2) + C * this->warm + D * sin(start_warm);
		return simulation;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	double time, temperature, warm;
	cout << "Введите температуру:"<<endl;
	cin >> temperature;
	cout << "Введите момент времени:" << endl;
	cin >> time;
	cout << "Введите количество тепла:" << endl;
	cin >> warm;
	TemperatureController tmp(time, temperature, warm);
	cout << "Линейная модель y(t) = " << tmp.LinearSimulation()<<endl;
	cout << "Нелинейная модель y(t) = " << tmp.NonLinearSimulation()<<endl;
	system("pause");
	return 0;
}

