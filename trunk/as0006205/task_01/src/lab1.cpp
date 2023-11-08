#include <iostream>
#include <cmath>
#include <vector>

const int n = 16;

void linearModel(std::vector<double>& y, double input, double coefA, double coefB) {
    std::vector<double> newTemp(n);

    for (int i = 1; i < n; i++) {
        y[i] = coefA * y[i - 1] + coefB * input;
        newTemp[i] = y[i];
    }

    // Вывод результатов для линейной модели
    std::cout << "For linear model:\n";
    for (int i = 1; i < n; i++) std::cout << "y[" << i << "] = " << newTemp[i] << " \n";
}

void nonLinearModel(std::vector<double>& y, double input, double coefA, double coefB, double coefC, double coefD) {
    std::vector<double> newTemp(n);

    for (int i = 2; i < n; i++) {
        y[i] = coefA * y[i - 1] - coefB * y[i - 2] + coefC * input + coefD * sin(input);
        newTemp[i] = y[i];
    }

    // Вывод результатов для нелинейной модели
    std::cout << "For nonlinear model:\n";
    for (int i = 2; i < n; i++) std::cout << "y[" << i << "] = " << newTemp[i] << " \n";
}

int main() {
    double coefA = 1.2;
    double coefB = -0.4;
    double coefC = 0.6;
    double coefD = -0.2;
    std::vector<double> y(n);
    double input;

    std::cout << "Input initial temperature: ";
    std::cin >> y[0];
    std::cout << "Input warming value: ";
    std::cin >> input;

    linearModel(y, input, coefA, coefB);
    nonLinearModel(y, input, coefA, coefB, coefC, coefD);

    return 0;
}
