#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void linearModel(float A, float B, float temp, float warm, int time)
{
    cout << endl << "LinModel:" << endl << endl;
    float currTempr = temp;
    for (int i = 0; i < time; i++)
    {
        currTempr = A * currTempr + B * warm;
        cout << "y(" << i + 1 << ") = " << currTempr << endl;
    }
    cout << endl;
}

void nonLinearModel(float A, float B, float C, float D, float temp, float warm, int time)
{
    cout << "NonLinMod:" << endl << endl;

    vector<float> temps;
    temps.resize(time);
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
            currentTemp = temps[i - 1];
            prevTemp = temp;
        }
        else
        {
            currentTemp = temps[i - 1];
            prevTemp = temps[i - 2];
        }

        temps[i] = A * currentTemp - B * (float)pow(prevTemp, 2) + C * warm + D * sin(warm);

        cout << "y(" << i + 1 << ") = " << temps[i] << endl;
    }
}

int main()
{
    const float A = 0.7f;
    const float B = 0.6f;
    const float C = 1.1f;
    const float D = 2.3f;
    float Tempr;
    float Warm;
    int Time;

    cout << "Input object temperature: ";
    cin >> Tempr;

    cout << "Input warm:";
    cin >> Warm;

    cout << "Input time limit:";
    cin >> Time;

    linearModel(A, B, Tempr, Warm, Time);
    nonLinearModel(A, B, C, D, Tempr, Warm, Time);

    return 0;
}