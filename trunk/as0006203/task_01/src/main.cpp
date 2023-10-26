#include <iostream>
#include <cmath>
#include <vector>

const int n = 16;

void linearModel(std::vector<double>& y, double u, double a, double b) {
    std::vector<double> newTemp(n);

    for (int i = 1; i < n; i++) {
        y[i] = a * y[i - 1] + b * u;
        newTemp[i] = y[i];
    }

    // Вывод результатов для линейной модели
    std::cout << "For linear model:\n";
    for (int i = 1; i < n; i++) std::cout << "y[" << i << "] = " << newTemp[i] << " \n";
}

void nonLinearModel(std::vector<double>& y, double u, double a, double b, double c, double d) {
    std::vector<double> newTemp(n);

    for (int i = 2; i < n; i++) {
        y[i] = a * y[i - 1] - b * y[i - 2] + c * u + d * sin(u);
        newTemp[i] = y[i];
    }

    // Вывод результатов для нелинейной модели
    std::cout << "For nonlinear model:\n";
    for (int i = 2; i < n; i++) std::cout << "y[" << i << "] = " << newTemp[i] << " \n";
}

int main() {
    double a = 1.2;
    double b = -0.4;
    double c = 0.6;
    double d = -0.2;
    std::vector<double> y(n);
    double u;

    std::cout << "Input initial temperature: ";
    std::cin >> y[0];
    std::cout << "Input warming value: ";
    std::cin >> u;

    linearModel(y, u, a, b);
    nonLinearModel(y, u, a, b, c, d);

    return 0;
}
