#ifndef MODEL_HPP
#define MODEL_HPP
#include <string>

class Model {
 private:
  double temperature;
  double warmth;
  double tau;

 public:
  Model(double temp, double warm, int time)
      : temperature(temp), warmth(warm), tau(time) {}

  std::string printData();
};

#endif