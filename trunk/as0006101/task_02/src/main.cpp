#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MathModel {
public:
    virtual double calcOutput(double Current_Value, double Previous_Value, double Input_Value) const = 0;
    virtual ~MathModel() = default;
};

class LinearModel : public MathModel {
private:
    double parameter_A;
    double parameter_B;

public:
    explicit LinearModel(double parameter_A, double parameter_B) : parameter_A(parameter_A), parameter_B(parameter_B) {}

    double calcOutput(double Current_Value, double Previous_Value, double Input_Value) const override {
        return parameter_A * Current_Value + parameter_B * Input_Value;
    }
};

class NonLinearModel : public MathModel {
private:
    double parameter_A;
    double parameter_B;
    double parameter_C;
    double parameter_D;

public:
    NonLinearModel(double parameter_A, double parameter_B, double parameter_C, double parameter_D)
        : parameter_A(parameter_A), parameter_B(parameter_B), parameter_C(parameter_C), parameter_D(parameter_D) {}

    double calcOutput(double Current_Value, double Previous_Value, double Input_Value) const override {
        return parameter_A * Current_Value - parameter_B * pow(Previous_Value, 2) + parameter_C * Input_Value + parameter_D * sin(Input_Value);
    }
};

class PID_Regulator {
private:
    double q0;
    double q1;
    double q3;
    double Previous_Error = 0.0;
    double Integral_Error = 0.0;
    double Previous_ControlSignal = 0.0;

public:
    explicit PID_Regulator(double q0, double q1, double q3)
        : q0(q0), q1(q1), q3(q3) {}

    double calcOutput(double Current_Error) {
        Integral_Error += Current_Error;
        double Derivative_Error = Current_Error - Previous_Error;
        double ControlSignal = q0 * Current_Error + q1 * Integral_Error + q3 * Derivative_Error;
        Previous_Error = Current_Error;
        Previous_ControlSignal = ControlSignal;
        return ControlSignal;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    double ParameterA_Linear = 0.8; double ParameterB_Linear = 0.5;

    double ParameterA_NonLinear = 0.8; double ParameterB_NonLinear = 0.5; double ParameterC_NonLinear = 0.2; double ParameterD_NonLinear = 0.1;

    double CurrentValue_Linear = 0.0; double CurrentValue_NonLinear = 0.0; double PreviousValue_NonLinear = 0.0;

    double Input_Value = 1.0;

    LinearModel LinModel(ParameterA_Linear, ParameterB_Linear);
    NonLinearModel NonLinModel(ParameterA_NonLinear, ParameterB_NonLinear, ParameterC_NonLinear, ParameterD_NonLinear);
    PID_Regulator pidRegulator(1.0, 0.5, 0.2);

    vector<double> Linear_Values;
    vector<double> NonLinear_Values;
    vector<double> Error_Values;
    vector<double> ControlSignal_Values;

    for (int t = 1; t <= 10; t++) {
        CurrentValue_Linear = LinModel.calcOutput(CurrentValue_Linear, 0, Input_Value);
        CurrentValue_NonLinear = NonLinModel.calcOutput(CurrentValue_NonLinear, PreviousValue_NonLinear, Input_Value);
        PreviousValue_NonLinear = CurrentValue_NonLinear;

        double Error = CurrentValue_Linear - CurrentValue_NonLinear;
        double ControlSignal = pidRegulator.calcOutput(Error);

        Linear_Values.push_back(CurrentValue_Linear);
        NonLinear_Values.push_back(CurrentValue_NonLinear);
        Error_Values.push_back(Error);
        ControlSignal_Values.push_back(ControlSignal);
    }

    for (int t = 0; t < 10; t++) {
        cout << "Iteration" << t + 1 << ":\n";
        cout << "Linear output: " << Linear_Values[t] << '\n';
        cout << "Nonlinear output: " << NonLinear_Values[t] << '\n';
        cout << "Error: " << Error_Values[t] << '\n';
        cout << "Control signal: " << ControlSignal_Values[t] << '\n';
        cout << '\n';
    }

    return 0;
}