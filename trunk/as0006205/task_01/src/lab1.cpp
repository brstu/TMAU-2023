#include <iostream>
#include <cmath>

// Линейная модель
double linearModel(double yT, double u1, double A, double B) {
    return A * yT + B * u1;
}

// Нелинейная модель
double nonlinearModel(double yT, double yT1, double u1, double A, double B, double cc, double dd) {
    return A * yT - B * pow(yT1, 2) + cc * u1 + dd * sin(U);
}

int main() {
    
    double a_lin = 0.8;
    double b_lin = 0.5;
    double a_nonlin = 0.8;
    double b_nonlin = 0.5;
    double c_nonlin = 0.2;
    double d_nonlin = 0.1;

   
    double Y_lin = 0.0;
    double Y_nonlin = 0.0;
    double Y_prev_nonlin = 0.0;

    // Входные значения
    double u1 = 1.0;

    // Моделирование для 10 временных шагов
    for (int T = 1; T <= 10; T++) {
        // Линейная модель
        Y_lin = linearModel(Y_lin, u1, a_lin, b_lin);

        // Нелинейная модель
        Y_nonlin = nonlinearModel(Y_nonlin, Y_prev_nonlin, u1, a_nonlin, b_nonlin, c_nonlin, d_nonlin);
        Y_prev_nonlin = Y_nonlin;

        std::cout << "time step: " << T << std::endl;
        std::cout << "Linear model: " << Y_lin << std::endl;
        std::cout << "Nonlinear model: " << Y_nonlin << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
