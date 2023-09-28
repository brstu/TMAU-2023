#include <iostream>
using namespace std;
int main()
{
	//Константы
    const double a = 1.1;
    const double b = 0.03;
    const double c = 0.7;
    const double d = 0.06;
    double Ytemp = 0;
    double Uwarm = 0;
    double Ytemp_1 = 17;
    double Uwarm_1 = 19;
	 //ВВод данных
    cout << "Input temperature: ";
    cin >> Ytemp;
    cout << "Input warm: ";
    cin >> Uwarm;
	 double y[15] = { 0 };
    y[0] = Ytemp_1;
    y[1] = Ytemp;
	 //Вычисления по формуле линейной модели
	 for (int i = 2; i < 15; i++) { y[i] = a * y[i - 1] + b * Uwarm; }
    cout << "For linear model:\n";
    for (int i = 0; i < 15; i++) cout << "y[" << i << "] = " << y[i] << " \n";
	 cout << "\n";
	 //Вычисления по формуле нелинейной модели
    for (int i = 2; i < 15; i++) { y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * Uwarm + d * sin(Uwarm_1); }
    cout << "For nonlinear model:\n";
    for (int i = 0; i < 15; i++) cout << "y["<< i <<"] = " << y[i] << " \n";
	 return 0;
}
