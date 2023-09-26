#include <iostream>
using namespace std;
int main()
{
    const double a = 1.1;
    const double b = 0.03;
    const double c = 0.7;
    const double d = 0.06;
    double Ytemp = 0;
    double Uwarm = 0;
    double Ytemp_1 = 17;
    double Uwarm_1 = 19;
    cout << "Input temperature: ";
    cin >> Ytemp;
    cout << "\nInput warm: ";
    cin >> Uwarm;
    cout << "\n";
    double y[15] = { 0 };
    y[0] = Ytemp_1;
    y[1] = Ytemp;
    for (int i = 2; i < 15; i++) {
        y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * Uwarm + d * sin(Uwarm_1);
    }
    cout << "For nonlinear model:\n";
    for (int i = 0; i < 15; i++) cout << "y["<< i <<"] = " << y[i] << " \n";
    cout << "\n";
    for (int i = 2; i < 15; i++) {
        y[i] = a * y[i - 1] + b * Uwarm;
    }
    cout << "For linear model:\n";
    for (int i = 0; i < 15; i++) cout << "y[" << i << "] = " << y[i] << " \n";
    return 0;
}