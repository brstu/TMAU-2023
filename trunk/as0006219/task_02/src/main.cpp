#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class MathModel {
public:
    virtual double calcOutput(double currentOutput, double previousOutput, double input) const = 0;
    virtual ~MathModel() = default;
};
class LinModel : public MathModel {
private:
    double coefficientA;
    double coefficientB;
public:
    explicit LinModel(double coefficientA, double coefficientB) : coefficientA(coefficientA), coefficientB(coefficientB) {}

    double calcOutput(double currentOutput, double previousOutput, double input) const override {
        return coefficientA * currentOutput + coefficientB * input;
    }
};
class NonlinModel : public MathModel {
private:
    double coefficientA;
    double coefficientB;
    double coefficientC;
    double coefficientD;
public:
    NonlinModel(double coefficientA, double coefficientB, double coefficientC, double coefficientD)
        : coefficientA(coefficientA), coefficientB(coefficientB), coefficientC(coefficientC), coefficientD(coefficientD) {}

    double calcOutput(double currentOutput, double previousOutput, double input) const override {
        return coefficientA * currentOutput - coefficientB * pow(previousOutput, 2) + coefficientC * input + coefficientD * sin(input);
    }
};
class PIDRegulator {
private:
    double gainP;
    double gainI;
    double gainD;
    double previousError = 0.0;
    double integralError = 0.0;
    double previousControlSignal = 0.0;
public:
    explicit PIDRegulator(double gainP, double gainI, double gainD)
        : gainP(gainP), gainI(gainI), gainD(gainD) {}

    double calcOutput(double currentError) {
        integralError += currentError;
        double derivativeError = currentError - previousError;
        double controlSignal = gainP * currentError + gainI * integralError + gainD * derivativeError;
        previousError = currentError;
        previousControlSignal = controlSignal;
        return controlSignal;
    }
};
int main() {
    setlocale(LC_ALL, "Russian");
    double coefficientA_linear = 0.8;
    double coefficientB_linear = 0.5;
    double coefficientA_nonlinear = 0.8;
    double coefficientB_nonlinear = 0.5;
    double coefficientC_nonlinear = 0.2;
    double coefficientD_nonlinear = 0.1;
    double currentOutput_linear = 0.0;
    double currentOutput_nonlinear = 0.0;
    double previousOutput_nonlinear = 0.0;
    double input = 1.0;
    LinModel linModel(coefficientA_linear, coefficientB_linear);
    NonlinModel nonlinModel(coefficientA_nonlinear, coefficientB_nonlinear, coefficientC_nonlinear, coefficientD_nonlinear);
    PIDRegulator pidRegulator(1.0, 0.5, 0.2);
    vector<double> currentOutput_linear_values;
    vector<double> currentOutput_nonlinear_values;
    vector<double> error_values;
    vector<double> controlSignal_values;
    for (int t = 1; t <= 10; t++) {
        currentOutput_linear = linModel.calcOutput(currentOutput_linear, 0, input);
        currentOutput_nonlinear = nonlinModel.calcOutput(currentOutput_nonlinear, previousOutput_nonlinear, input);
        previousOutput_nonlinear = currentOutput_nonlinear;

        double error = currentOutput_linear - currentOutput_nonlinear;
        double controlSignal = pidRegulator.calcOutput(error);

        currentOutput_linear_values.push_back(currentOutput_linear);
        currentOutput_nonlinear_values.push_back(currentOutput_nonlinear);
        error_values.push_back(error);
        controlSignal_values.push_back(controlSignal);
    }
    for (int t = 0; t < 10; t++) {
        cout << "Итерация " << t + 1 << ":\n";
        cout << "Выход линейной модели: " << currentOutput_linear_values[t] << '\n';
        cout << "Выход нелинейной модели: " << currentOutput_nonlinear_values[t] << '\n';
        cout << "Ошибка: " << error_values[t] << '\n';
        cout << "Управляющий сигнал: " << controlSignal_values[t] << '\n';
        cout << '\n';
    }
    return 0;
}