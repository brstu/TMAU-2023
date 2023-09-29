#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

class Model {
 private:
  double temp;
  double warm;
  double time;

 public:
  Model(double temp, double warm, int time)
      : temp(temp), warm(warm), time(time) {}
  std::string toString() {
    std::ostringstream oss;
    oss << "temp: " << std::fixed << std::setprecision(2) << temp
        << " warm: " << warm << " time: " << time;
    return oss.str();
  }
};

// Some physical constants
const double A = 0.5;
const double B = 1;
const double C = 1.2;
const double D = 0.4;
// Discrete value taken as const of 1
const int WARM = 1;

std::vector<Model> simulateLinear(double temp, int time) {
  std::vector<Model> models;
  for (size_t t = 1; t <= time; t++) {
    temp = A * temp + B * WARM;
    models.push_back(Model(temp, WARM, t));
  }

  return models;
}

std::vector<Model> simulateNonLinear(double temp, int time) {
  std::vector<Model> models;
  int prevTemp = 0;

  for (size_t t = 1; t <= time; t++) {
    temp = A * temp - B * pow(prevTemp, 2) + C * WARM + D * sin(WARM);
    models.push_back(Model(temp, WARM, t));
    prevTemp = temp;
  }
  return models;
}

void logData(std::vector<Model> models) {
  for (auto &model : models) {
    std::cout << model.toString() << std::endl;
  }
}

int main() {
  int time;
  int initialTemperature;
  std::cout << "Input time parameter: ";
  std::cin >> time;
  std::cout << std::endl;
  std::cout << "Input initial temperature: ";
  std::cin >> initialTemperature;

  std::cout << "Linear model:" << std::endl;
  logData(simulateLinear(initialTemperature, time));
  std::cout << std::endl;

  std::cout << "Non linear model:" << std::endl;
  logData(simulateNonLinear(initialTemperature, time));
  std::cout << "." << std::endl;

  std::cout << "Press Enter to exit...";
  std::cin.ignore();
  std::cin.get();

  return 0;
}