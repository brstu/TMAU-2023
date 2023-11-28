#include <iostream>
#include <cmath>

class AbstractModel {
public:
    virtual double simulateTemperature(double currentTemperature, double inputWarm) = 0;
    virtual ~AbstractModel() = default;
};

class LinearModel : public AbstractModel {
private:
    double coefficientA;
    double coefficientB;

public:
    LinearModel(double a, double b) : coefficientA(a), coefficientB(b) {}

    double simulateTemperature(double currentTemperature, double inputWarm) override {
        return coefficientA * currentTemperature + coefficientB * inputWarm;
    }

    ~LinearModel() override = default;
};

class NonlinearModel : public AbstractModel {
private:
    double coefficientA;
    double coefficientB;
    double coefficientC;
    double coefficientD;
    double prevTemperature = 0;
    double prevInputWarm = 0;
    bool isFirstStep = true; // Флаг для отслеживания первого шага моделирования
    
public:
    NonlinearModel(double a, double b, double c, double d) :
        coefficientA(a),
        coefficientB(b),
        coefficientC(c),
        coefficientD(d) {}

    double simulateTemperature(double currentTemperature, double inputWarm) override {
        double calculatedTemperature;

        if (isFirstStep) {
            calculatedTemperature = coefficientA * currentTemperature + coefficientC * inputWarm;
            isFirstStep = false;
        }
        else {
            calculatedTemperature = coefficientA * currentTemperature - coefficientB * pow(prevTemperature, 2) + coefficientC * inputWarm + coefficientD * sin(prevInputWarm);
        }

        prevTemperature = currentTemperature;
        prevInputWarm = inputWarm;
        return calculatedTemperature;
    }

    ~NonlinearModel() override = default;
};


class PIDRegulator {
private:
    const double transferCoefficientK = 0.1;
    const double integrationConstantT = 10;
    const double differentiationConstantTD = 80;
    const double quantizationStepT0 = 50;
    const double simulationTime = 30;
    double controlVariableUk = 0;

    double calculateControlVariable(double deviation, double prevDeviation, double prevPrevDeviation) {
        double q0 = transferCoefficientK * (1 + differentiationConstantTD / quantizationStepT0);
        double q1 = -transferCoefficientK * (1 + 2 * differentiationConstantTD / quantizationStepT0 - quantizationStepT0 / integrationConstantT);
        double q2 = transferCoefficientK * differentiationConstantTD / quantizationStepT0;
        controlVariableUk += q0 * deviation + q1 * prevDeviation + q2 * prevPrevDeviation;
        return controlVariableUk;
    }

public:
    void regulate(double desiredValue, double initialTemperature, AbstractModel& model) {
        double prevDeviation = 0;
        double prevPrevDeviation = 0;
        double currentTemperature = initialTemperature;

        for (int i = 1; i <= simulationTime; i++) {
            double deviation = desiredValue - currentTemperature;
            controlVariableUk = calculateControlVariable(deviation, prevDeviation, prevPrevDeviation);
            currentTemperature = model.simulateTemperature(initialTemperature, controlVariableUk);

            std::cout << "Deviation(E) = " << deviation << ", Current Temperature(Yt) = " << currentTemperature << ", Control Variable(Uk) = " << controlVariableUk << std::endl;

            prevPrevDeviation = prevDeviation;
            prevDeviation = deviation;
        }

        controlVariableUk = 0;
    }
};

void inputParameters(double& a, double& b, double& c, double& d, bool isNonlinearModel) {
    std::cout << "Input parameter a: "; std::cin >> a;
    std::cout << "Input parameter b: "; std::cin >> b;

    if (isNonlinearModel) {
        std::cout << "Input parameter c: "; std::cin >> c;
        std::cout << "Input parameter d: "; std::cin >> d;
    }
}

int main() {
    const double desiredValue = 8;
    const double initialTemperature = 3;
    double a;
    double b;
    double c;
    double d;

    std::cout << "Input Linear Model's parameters" << std::endl;
    inputParameters(a, b, c, d, false);
    LinearModel linearModel{ a, b };

    std::cout << "Input Nonlinear Model's parameters" << std::endl;
    inputParameters(a, b, c, d, true);
    NonlinearModel nonlinearModel{ a, b, c, d };

    PIDRegulator pidRegulator;

    std::cout << "\tLinear Model:" << std::endl;
    pidRegulator.regulate(desiredValue, initialTemperature, linearModel);
    std::cout << std::endl;

    std::cout << "\tNonlinear Model" << std::endl;
    pidRegulator.regulate(desiredValue, initialTemperature, nonlinearModel);

    system("Pause");
}
