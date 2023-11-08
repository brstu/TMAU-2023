#include <iostream>
#include <cmath>
#include <array>
using namespace std;
int main()
{
    double yourTemp = 0;
    double yourWarm = 0;
    double yourTemp_1 = 14;
    double yourWarm_1 = 22;
    const double a = 0.8;
    const double b = 0.05;
    const double c = 0.42;
    const double d = 0.1;
	 //Input
    cout << "Input temperature: ";
    cin >> yourTemp;
    cout << "Input warm: ";
    cin >> yourWarm;
	 array<double,15> arrayOfTemperature = { 0 };
    arrayOfTemperature[0] = yourTemp_1;
    arrayOfTemperature[1] = yourTemp;
	 //Linear model
	 for (int i = 2; i < 15; i++) { arrayOfTemperature[i] = a * arrayOfTemperature[i - 1] + b * yourWarm; }
    cout << "For linear model:\n";
    for (int j = 0; j < 15; j++) cout << "Temperature at the " << j << " time: " << arrayOfTemperature[j] << (arrayOfTemperature[j]>20?". It is good":". It is bad") <<" \n";
	 cout << "\n";
	 //Unlinear model
    for (int k = 2; k < 15; k++) { arrayOfTemperature[k] = a * arrayOfTemperature[k - 1] - b * pow(arrayOfTemperature[k - 2], 2) + c * yourWarm + d * sin(yourWarm_1); }
    cout << "For nonlinear model:\n";
    for (int t = 0; t < 15; t++) cout << "Temperature at the "<< t <<" time: " << arrayOfTemperature[t] << (arrayOfTemperature[t]>20?". It is good":". It is bad") << " \n";
	 return 0;
}