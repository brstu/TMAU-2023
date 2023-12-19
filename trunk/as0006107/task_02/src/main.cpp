#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MathematicModel {
public:
    virtual double CountOutput(double CurrVal, double PrevVal, double InputVal) const = 0;
    virtual ~MathematicModel() = default;
};

class LinearModel : public MathematicModel {
private:
    double coeff_a;
    double coeff_b;

public:
    explicit LinearModel(double coeff_a, double coeff_b) : coeff_a(coeff_a), coeff_b(coeff_b) {}

    double CountOutput(double CurrVal, double PrevVal, double InputVal) const override {
        return coeff_a * CurrVal + coeff_b * InputVal;
    }
};

class NonLinearModel : public MathematicModel {
private:
    double coeff_a;
    double coeff_b;
    double coeff_c;
    double coeff_d;

public:
    NonLinearModel(double coeff_a, double coeff_b, double coeff_c, double coeff_d)
        : coeff_a(coeff_a), coeff_b(coeff_b), coeff_c(coeff_c), coeff_d(coeff_d) {}

    double CountOutput(double CurrVal, double PrevVal, double InputVal) const override {
        return coeff_a * CurrVal - coeff_b * pow(PrevVal, 2) + coeff_c * InputVal + coeff_d * sin(InputVal);
    }
};

class Regulator {
private:
    double q0;
    double q1;
    double q3;
    double DeviationVal_1 = 0.0;
    double DeviationVal_2 = 0.0;
    double ControlAction_1 = 0.0;

public:
    explicit Regulator(double q0, double q1, double q3) : q0(q0), q1(q1), q3(q3) {}

    double CountOutput(double Current_Error) {
        DeviationVal_2 += Current_Error;
        double Derivative_Error = Current_Error - DeviationVal_1;
        double ControlAct = q0 * Current_Error + q1 * DeviationVal_2 + q3 * Derivative_Error;
        DeviationVal_1 = Current_Error;
        ControlAction_1 = ControlAct;
        return ControlAct;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    double LinearParam_a = 0.8; double LinearParam_b = 0.5;

    double NonLinearParam_a = 0.8; double NonLinearParam_b = 0.5; double NonLinearParam_c = 0.2; double NonLinearParam_d = 0.1;

    double LinerVal = 0.0; double NonLinearVal = 0.0; double NonLinearPrevVal = 0.0;

    double Value_1 = 1.0;

    LinearModel LinModel(LinearParam_a, LinearParam_b);
    NonLinearModel NonLinearModel(NonLinearParam_a, NonLinearParam_b, NonLinearParam_c, NonLinearParam_d);
    Regulator pidRegulator(1.0, 0.5, 0.2);

    vector<double> LinearVal;
    vector<double> NonLinearValues;
    vector<double> ValuesErr;
    vector<double> ControlSignal_Values;

    for (int i = 1; i <= 15; i++) {
        LinerVal = LinModel.CountOutput(LinerVal, 0, Value_1);
        NonLinearVal = NonLinearModel.CountOutput(NonLinearVal, NonLinearPrevVal, Value_1);
        NonLinearPrevVal = NonLinearVal;

        double Error = LinerVal - NonLinearVal;
        double ControlSignal = pidRegulator.CountOutput(Error);

        LinearVal.push_back(LinerVal);
        NonLinearValues.push_back(NonLinearVal);
        ValuesErr.push_back(Error);
        ControlSignal_Values.push_back(ControlSignal);
    }

    for (int i = 0; i < 15; i++) {
        cout << "Итерация:" << i + 1 << ":\n";
        cout << "Выоход линейной модели: " << LinearVal[i] << '\n';
        cout << "Выход нелинейной модели: " << NonLinearValues[i] << '\n';
        cout << "Ошибка: " << ValuesErr[i] << '\n';
        cout << "Управляющий сигнал: " << ControlSignal_Values[i] << '\n';
        cout << '\n';
    }

    return 0;
}