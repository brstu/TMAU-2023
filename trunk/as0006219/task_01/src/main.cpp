#include <iostream>
#include <cmath>
using namespace std;
double linMod(double inputTemperature_Yt, double inputWarm_U, double a, double b)
{
	return (a * inputTemperature_Yt) + (b* inputWarm_U);
}
double nolMod(double inputTemperature_Yt, double inputTemperature_Yt_1, double inputWarm_U, double a, double b, double c, double d)  
{
	return (a * inputTemperature_Yt) - b * pow(inputTemperature_Yt_1, 2) + (c*inputWarm_U) + d * sin(inputWarm_U);
}
int main(){
	setlocale(LC_ALL, "rus");
	double lina = 1.6; 
	double linb = 0.9;
	double nola = 0.8;
    double nolb = 0.6;
	double nolc = 0.5;
	double nold = 0.3;
	double liny = 0.0;
	double noly = 0.0;
	double prenoly = 0.0;
	double W = 0;
	int t;

	cout << "Введите тепло: ";
	cin >> W;

	cout << "Введите время: ";
	cin >> t;

	cout << endl;

	for (int i = 1; i <= t; i++) 
	{
		liny = linMod(liny, W, lina, linb);
		noly = nolMod(noly, prenoly, W, nola, nolb, nolc, nold);
		prenoly = noly;
		cout << "Время: " << i << endl;
		cout << "Линейная модель: " << liny << endl;
		cout << "Нелинейная модель: " << noly << endl << endl;
	}
}