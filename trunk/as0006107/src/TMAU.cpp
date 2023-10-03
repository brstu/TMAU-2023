#include <iostream>
#include <cmath>
using namespace std;
// Линейная модель
double linModel( double y_t, double u, double a, double b) {
    return a * y_t + b * u;
}

// Нелинейная модель
double NolinModel(double y_t, double y_t1, double u, double a, double b, double c, double d) {
    return a * y_t - b * pow(y_t1, 2) + c * u + d * sin(u);
}

int main() {
    setlocale(LC_ALL, "Russian");
    double u = 1.0;
    double y_linm = 0.0;
    double a_linm = 0.55;
    double b_linm = 0.55;

    double y_nolinm = 0.0;
    double y_prednolinm = 0.0;
    double a_nolinm = 0.55;
    double b_nolinm = 0.55;
    double c_nolinm = 0.33;
    double d_nolinm = 0.22;

    for (int i = 1; i <= 15; i++) {

        y_linm = linModel(y_linm, u, a_linm, b_linm);

        y_nolinm = NolinModel(y_nolinm, y_prednolinm, u, a_nolinm, b_nolinm, c_nolinm, d_nolinm);
        y_prednolinm = y_nolinm;

        
        cout << "Шаг: " << i << endl;
        cout << "Линейная модель: " << y_linm << endl;
        cout << "Нелинейная модель: " << y_nolinm << endl;
        cout << "  " << endl;
    }
}