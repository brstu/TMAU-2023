#include <iostream>
#include <cmath>
#include <vector>

constexpr int N = 16;    // количество изменений температуры

double linear_transformation(std::vector<double>& y, double u, double a, double b) {
    std::vector<double> new_temperature(N);

    for (int i = 1; i < N; i++) {
        y[i] = a * y[i - 1] + b * u;
        new_temperature[i] = y[i];
    }
    return new_temperature[N - 1];
}

double nonlinear_transformation(std::vector<double>& y, double u, double a, double b, double c, double d) {
    std::vector<double> new_temperature(N);
    y[1] = a * y[0] + b * u;
    new_temperature[1] = y[1];

    for (int i = 2; i < N; i++) {
        y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * u + d * sin(u);
        new_temperature[i] = y[i];
    }
    return new_temperature[N - 1];
}

int choose_transformation() {
    std::vector<double> temperature(N);
    double warm;
    const double a = 0.1;
    const double b = 0.1;
    const double c = 0.3;
    const double d = 0.2;
    int temp;

    std::cout << "choose type of transformation: \n 1 - linear \n 2 - nonlinear" << std::endl;
    std::cin >> temp;
    std::cout << "enter temperature " << std::endl;
    std::cin >> temperature[0];
    std::cout << "enter warm " << std::endl;
    std::cin >> warm;
    std::cout << "\n";

    if (temp == 1) {
        linear_transformation(temperature, warm, a, b);
        for (int i = 0; i < N; i++) {
            std::cout << "y[" << i << "]=" << temperature[i] << std::endl;
        }
    }
    else {
        nonlinear_transformation(temperature, warm, a, b, c, d);
        for (int i = 0; i < N; i++) {
            std::cout << "y[" << i << "]=" << temperature[i] << std::endl;
        }
    }

    return 0;
}

int main() {
    choose_transformation();

    system("pause");
    return 0;
}
