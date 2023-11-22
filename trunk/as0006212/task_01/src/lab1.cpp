#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int n = 16;
void linear(vector<double>& y, double warm, double coef1, double coef2) {
    vector<double> newTemp(n);
    for (int i = 1; i < n; i++) {
        y[i] = coef1 * y[i - 1] + coef2 * warm;
        newTemp[i] = y[i];
    }
    cout << "для линейной:\n";
    for (int i = 1; i < n; i++) cout << "y[" << i << "] = " << newTemp[i] << " \n";
}
void nonLinear(vector<double>& y, double warm, double coef1, double coef2, double coef3, double coef4) {
    vector<double> newTemp(n);
    for (int i = 2; i < n; i++) {
        y[i] = coef1 * y[i - 1] - coef2 * y[i - 2] + coef3 * warm + coef4 * sin(warm);
        newTemp[i] = y[i];
    }
    cout << "для нелинейной:\n";
    for (int i = 2; i < n; i++) cout << "y[" << i << "] = " << newTemp[i] << " \n";
}
int main() {
    setlocale(LC_ALL, "Russian");
    double coef1 = 1.2, coef2 = -0.4, coef3 = 0.6, coef4 = -0.2, warm;
    vector<double> y(n);
    cout << "Входная начальная температура: ";
    cin >> y[0];
    cout << "Введите значение потепления: ";
    cin >> warm;
    linear(y, warm, coef1, coef2);
    nonLinear(y, warm, coef1, coef2, coef3, coef4);
}
