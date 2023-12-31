#include "model.hpp"

#include <iomanip>

std::string Model::printData() const {
  std::ostringstream oss;
  oss << "temp: " << std::fixed << std::setprecision(2) << temperature
      << " warm: " << warmth << " time: " << tau;
  return oss.str();
}