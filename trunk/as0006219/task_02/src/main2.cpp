#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Math {
public:
	virtual double Calc(double currentOutput, double previousOutput, double input) const = 0;
	virtual ~Math() = default;
};
class LinModel : public Math {
private:
	double A;
	double B;
public:
	explicit LinModel(double A, double B) : A(A), B(B) {}
	double Calc(double curout, double previousOutput, double input) const override {
		return A * curout + B * input;
	}
};
class NonlinModel : public Math {
private:
	double A;
	double B;
	double C;
	double D;
public:
	NonlinModel(double A, double B, double C, double D)
		: A(A), B(B), C(C), D(D) {}
	double Calc(double current, double previous, double input) const override {
		return A * current - B * pow(previous, 2) + C * input + D * sin(input);
	}
};
class PID {
private:
	double P;
	double I;
	double D;
	double previous = 0.0;
	double integral = 0.0;
	double previousControlSignal = 0.0;
public:
	explicit PID(double P, double I, double D)
		: P(P), I(I), D(D) {}
	double calcout(double currentError) {
		integral += currentError;
		double derivativeError = currentError - previous;
		double controlSignal = P * currentError + I * integral + D * derivativeError;
		previous = currentError;
		previousControlSignal = controlSignal;
		return controlSignal;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	double A_lin = 0.8;
	double B_lin = 0.5;
	double A_nonlin = 0.8;
	double B_nonlin = 0.5;
	double C_nonlin = 0.2;
	double D_nonlin = 0.1;
	double curoutlin = 0.0;
	double curoutnonlin = 0.0;
	double prevoutnonlin = 0.0;
	double input = 1.0;
	LinModel linModel(A_lin, B_lin);
	NonlinModel nonlinModel(A_nonlin, B_nonlin, C_nonlin, D_nonlin);
	PID pid(1.0, 0.5, 0.2);
	vector<double> curoutlinvalues;
	vector<double> curoutnonlinvalues;
	vector<double> errvalues;
	vector<double> controlsignvalues;
	for (int i = 0; i <= 9; i++) {
		curoutlin = linModel.Calc(curoutlin, 0, input);
		curoutnonlin = nonlinModel.Calc(curoutnonlin, prevoutnonlin, input);
		prevoutnonlin = curoutnonlin;
		double error = curoutlin - curoutnonlin;
		double consign = pid.calcout(error);
		curoutlinvalues.push_back(curoutlin);
		curoutnonlinvalues.push_back(curoutnonlin);
		errvalues.push_back(error);
		controlsignvalues.push_back(consign);
	}
	for (int i = 0; i <= 9; i++) {
		cout << "Итерация " << i + 1 << ":\n";
		cout << "Выход линейной модели: " << curoutlinvalues[i] << '\n';
		cout << "Выход нелинейной модели: " << curoutnonlinvalues[i] << '\n';
		cout << "Ошибка: " << errvalues[i] << '\n';
		cout << "Управляющий сигнал: " << controlsignvalues[i] << '\n';
		cout << '\n';
	}
	return 0;
}