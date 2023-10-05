#include <iostream>
#include <cmath>

// Линейная модель
double linearModel(double Yt, double U, double a, double b) {
    return a * Yt + b * U;
}

// Нелинейная модель
double nonlinearModel(double Yt, double Yt_1, double U, double a, double b, double c, double d) {
    return a * Yt - b * pow(Yt_1, 2) + c * U + d * sin(U);
}

int main() {
    
    double a_linear = 0.8;
    double b_linear = 0.5;
    double a_nonlinear = 0.8;
    double b_nonlinear = 0.5;
    double c_nonlinear = 0.2;
    double d_nonlinear = 0.1;

   
    double Y_linear = 0.0;
    double Y_nonlinear = 0.0;
    double Y_prev_nonlinear = 0.0;

    // Входные значения
    double U = 1.0;

    // Моделирование для 10 временных шагов
    for (int t = 1; t <= 10; t++) {
        // Линейная модель
        Y_linear = linearModel(Y_linear, U, a_linear, b_linear);

        // Нелинейная модель
        Y_nonlinear = nonlinearModel(Y_nonlinear, Y_prev_nonlinear, U, a_nonlinear, b_nonlinear, c_nonlinear, d_nonlinear);
        Y_prev_nonlinear = Y_nonlinear;

        std::cout << "time step: " << t << std::endl;
        std::cout << "Linear model: " << Y_linear << std::endl;
        std::cout << "Nonlinear model: " << Y_nonlinear << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}