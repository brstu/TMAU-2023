#include <iostream>
#include <cmath>
using namespace std;

//линейная модель
void linear(double a, double b, double uT, double yT, int t) {
    cout << "\t---Temperature modelling using a linear model---" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT + b * uT;
        cout << "y" << i << " = " << yT1 << endl;

        yT = yT1;
    }
}

//НЕлинейная модель
void nonLinear(double a, double b, double c, double d, double uT, double yT, int t) {
    double uT_1 = 0;
    double yT_1 = 0;

    cout << "\t---Temperature modelling using a NON-linear model---" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT - b * pow(yT_1, 2) + c * uT + d * sin(uT_1);
        cout << "y" << i << " = " << yT1 << endl;

        uT_1 = uT;
        yT_1 = yT;
        yT = yT1;
    }
}

int main() {
    double a; //константа
    double b; //константа
    double c; //константа
    double d; //константа
    double uT; //теплота
    double yT; //температура
    int t; // кол-во дискретных моментов времени

    cout << "Enter the constant a "; cin >> a;
    cout << "Enter the constant b "; cin >> b;
    cout << "Enter the constant c "; cin >> c;
    cout << "Enter the constant d "; cin >> d;
    cout << "Enter the warm "; cin >> uT;
    cout << "Enter the  temperature "; cin >> yT;
    cout << "Enter the number of discrete times "; cin >> t;

    linear(a, b, uT, yT, t);
    nonLinear(a, b, c, d, uT, yT, t);

    return 0;
}
