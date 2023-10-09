#include <iostream>
#include <cmath>

using namespace std;

void linearModel(float A, float B, float temp, float warm, int time)
{
    cout << endl << "LinearModel:" << endl << endl;

    float currentTemp = temp;

    for (int i = 0; i < time; i++)
    {
        currentTemp = A * currentTemp + B * warm;

        cout << "y(" << i + 1 << ") = " << currentTemp << endl;
    }

    cout << endl;
}

void nonLinearModel(float A, float B, float C, float D, float temp, float warm, int time)
{
    cout << "NonLinearModel:" << endl << endl;

    float* temps = new float[time];

    for (int i = 0; i < time; i++)
    {
        int currentTemp, prevTemp;

        if (i == 0)
        {
            currentTemp = temp;
            prevTemp = temp;
        }
        else if(i == 1)
        {
            currentTemp = temps[i - 1];
            prevTemp = temp;
        }
        else
        {
            currentTemp = temps[i - 1];
            prevTemp = temps[i - 2];
        }

        temps[i] = A * currentTemp - B * pow(prevTemp, 2) + C * warm + D * sin(warm);

        cout << "y(" << i + 1 << ") = " << temps[i] << endl;
    }

    delete[] temps;
}

int main()
{
    const float A = 0.8;
    const float B = 0.5;
    const float C = 2.1;
    const float D = 1.3;
    
    float temp, warm;
    int time;

    cout << "Input object temperature: ";
    cin >> temp;
    
    cout << "Input warm:";
    cin >> warm;

    cout << "Input time limit:";
    cin >> time;

    linearModel(A, B, temp, warm, time);
    nonLinearModel(A, B, C, D, temp, warm, time);

    return 0;
}