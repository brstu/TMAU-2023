#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
void linearModel(float A, float B, float temperat, float warm, int time)
{
    cout << "LinearModel:" << endl;
    float currTempr = temperat;
    int w = 0;
    while (w < time)
    {
        currTempr = A * currTempr + B * warm;
        cout << "y[" << w + 1 << "] = " << currTempr << endl;
        w++;
    }
}

void nonLinearModel(float a, float b, float c, float d, float temp, float warm, int time)
{
    cout << "NonLinearModel:" << endl;
    vector<float> listOfTemps;
    listOfTemps.resize(time);
    for (int i = 0; i < time; i++)
    {
        float currentTemp;
        float prevTemp;
        if (i == 0)
        {
            currentTemp = temp;
            prevTemp = temp;
        }
        else if (i == 1)
        {
            currentTemp = listOfTemps[i - 1];
            prevTemp = temp;
        }
        else
        {
            currentTemp = listOfTemps[i - 1];
            prevTemp = listOfTemps[i - 2];
        }
        listOfTemps[i] = a * currentTemp - b * (float)pow(prevTemp, 2) + c * warm + d * sin(warm);

        cout << "y[" << i + 1 << "] = " << listOfTemps[i] << endl;
    }
}

int main()
{
    float a = 0.7f;
    float b = 0.6f;
    float d = 2.3f;
    float c = 1.1f;
    float temperature;
    float warm;
    int time;
    cout << "Введи температуру объекта: "; cin >> temperature;
    cout << "Введи тепло:"; cin >> warm;
    cout << "Введи временной предел:"; cin >> time;
    linearModel(a, b, temperature, warm, time);
    nonLinearModel(a, b, c, d, temperature, warm, time);
    return 0;
}
