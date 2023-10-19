#include <iostream>
#include <cmath>
using namespace std;

class TempController
{
    const double A = 2.3;
    const double B = 0.7;
    const double C = 1.5;
    const double D = 3;
    double temperature;
    double warm;



public:
    TempController(double temperature, double warm) : temperature(temperature), warm(warm)
    {
        
    }

    double NonLinearSimulation() const
    {
        double start_temperature = 1;
        double start_warm = 1;
        double simulation = A * this->temperature - B * pow(start_temperature, 2) + C * this->warm + D * sin(start_warm);
        return simulation;
    }

    double LinearSimulation() const
    {
        double y = A * this->temperature + B * this->warm;
        return y;
    }

};
int main()
{
    setlocale(LC_ALL, "rus");
    double time;
    double temperature;
    double warm;
    cout << "Введите температуру в комнате:" << endl;
    cin >> temperature;
    cout << "Введите момент времени на данный момент:" << endl;
    cin >> time;
    cout << "Введите количество тепла в комнате:" << endl;
    cin >> warm;
    TempController tmp(time, temperature, warm);
    cout << "Нелинейная модель y(t) = " << tmp.NonLinearSimulation() << endl;
    cout << "Линейная модель y(t) = " << tmp.LinearSimulation() << endl;
    system("pause");
    return 0;
}
