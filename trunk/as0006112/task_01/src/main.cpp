#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class TemperatureModel {
public:
    double temp;
    double warm;
    int t;

    TemperatureModel(double temp, double warm, int t) {
        this->temp = temp;
        this->warm = warm;
        this->t = t;
    }

    std::string toString() const {
        return "{ y(t): " + std::to_string(this->temp) + "; t: " + std::to_string(this->t) + " }";
    }
};

const double A = 0.5;
const double B = 1;
const double C = 1.2;
const double D = 0.4;
const double WARM = 1;

void showData(std::vector<TemperatureModel>& tempModels) {
    for (const auto& model : tempModels) {
        std::cout << model.toString() << std::endl;
    }
}

std::vector<TemperatureModel> simulateLinearModel(int time, double temp) {
    std::vector<TemperatureModel> linearTemps;

    for (int t = 1; t <= time; t++) {
        double curWarm = WARM;
        temp = round((A * temp + B * curWarm) * 100) / 100;
        linearTemps.push_back(TemperatureModel(temp, curWarm, t));
    }

    return linearTemps;
}

std::vector<TemperatureModel> simulateNonLinearModel(int time, double temp) {
    std::vector<TemperatureModel> nonLinearTemps;
    double prevTemp = 0;
    double prevWarm = 0;

    for (int t = 1; t <= time; t++) {
        double curWarm = WARM;
        temp = A * temp - B * pow(prevTemp, 2) + C * curWarm + D * sin(prevWarm);
        temp = round(temp * 100) / 100;
        nonLinearTemps.push_back(TemperatureModel(temp, curWarm, t));
        prevTemp = temp;
        prevWarm = curWarm;
    }

    return nonLinearTemps;
}

int main()
{
    int time;
    std::cout << "Input time parameter: ";
    std::cin >> time;

    int temp;
    std::cout << "Input initial temperature: ";
    std::cin >> temp;

    std::cout << "Linear model data" << std::endl;
    auto linear = simulateLinearModel(time, temp);
    showData(linear);

    std::cout << "Non linear model data" << std::endl;
    auto nonLinear = simulateNonLinearModel(time, temp);
    showData(nonLinear);

    return 0;
}