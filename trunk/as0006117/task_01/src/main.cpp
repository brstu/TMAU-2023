#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#include "lib/model.hpp"

// Some physical constants
const double A_CONST = 0.5;
const double B_CONST = 1;
const double C_CONST = 1.2;
const double D_CONST = 0.4;
// Discrete value taken as const of 1
const int WARMTH = 1;

std::vector<Model> simulateLinear(double temperature, int tau) {
  std::vector<Model> models;
  for (int t = 1; t <= tau; t++) {
    temperature = A_CONST * temperature + B_CONST * WARMTH;
    models.emplace_back(Model(temperature, WARMTH, t));
  }

  return models;
}

std::vector<Model> simulateNonLinear(double temperature, int tau) {
  std::vector<Model> models;
  double prevTemperetureValue = 0;

  for (int t = 1; t <= tau; t++) {
    temperature = A_CONST * temperature -
                  B_CONST * pow(prevTemperetureValue, 2) + C_CONST * WARMTH +
                  D_CONST * sin(WARMTH);
    models.emplace_back(Model(temperature, WARMTH, t));
    prevTemperetureValue = temperature;
  }
  return models;
}

void logData(std::vector<Model> superMegaModels) {
  for (auto &superMegaModel : superMegaModels) {
    std::cout << superMegaModel.printData() << std::endl;
  }
}

int main() {
  int tau;
  double initialTemperature;
  std::cout << "Input time parameter: ";
  std::cin >> tau;
  std::cout << std::endl;
  std::cout << "Input initial temperature: ";
  std::cin >> initialTemperature;

  std::cout << "Linear model:" << std::endl;
  logData(simulateLinear(initialTemperature, tau));
  std::cout << std::endl;

  std::cout << "Non linear model:" << std::endl;
  logData(simulateNonLinear(initialTemperature, tau));
  std::cout << "." << std::endl;

  std::cout << "Press Enter to exit...";
  std::cin.ignore();
  std::cin.get();

  return 0;
}