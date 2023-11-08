#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double a = 1.34; const double b = 5.23; const double c = 4.37; const  double d = 3.95;

double Linear_Model(double yt, double ut)
{
    return a * yt + b * ut;
}

double NotLinear_Model(double yt, double Prev_yt, double ut, double Prev_ut)
{
    return a * yt - b * pow(Prev_yt, 2) + c * ut + d * sin(Prev_ut);
}

int main()
{   setlocale(LC_ALL, "Russian");
    double yt; double ut; double Prev_yt; double Prev_ut; double y1; double u1; double A; double B; 
    int Linear; int NotLinear;
    cout << "Параметры линейной модели" << endl;
    cout << "Введите a:\t";
    cin >> A;
    cout << "Введите b:\t";
    cin >> B;
    cout << "Введите y:\t";
    cin >> y1;
    cout << "Введите u:\t";
    cin >> u1;
    cout << endl;
    cout << "Количество тестов" << endl;
    cout << "Линейная модель: ";
    cin >> Linear;
    cout << "Нелинейная модель: ";
    cin >> NotLinear;
    cout << endl;
    cout << "Линейная модель";
    yt = y1; ut = u1;
    for (int iter = 0; iter < Linear; iter++) {
        cout << endl;
        cout << "Введите ut: ";
        cin >> ut;
        yt = Linear_Model(yt, ut);
        cout << "Шаг: " << iter + 1 << ";" << " yt: " << yt;
    }
    cout << endl;
    cout << endl;
    cout << "Нелинейная модель";
    yt = y1; ut = u1;
    for (int iter = 0; iter < NotLinear; iter++) {
        if (iter > 0) {
            Prev_ut = ut; Prev_yt = yt;
            cout << endl;
            cout << "Введите yt: ";
            cin >> ut;
            yt = NotLinear_Model(yt, Prev_yt, ut, Prev_ut);
            cout << "Шаг: " << iter + 1 << ";" << " yt: " << yt;
        }
        else {
            Prev_ut = 0; Prev_yt = 0;
            cout << endl;
            cout << "Введите ut: ";
            cin >> ut;
            yt = NotLinear_Model(yt, Prev_yt, ut, Prev_ut);
            cout << "Шаг: " << iter + 1 << ";" << " yt: " << yt;
        }
        cout << endl;
    }
}
