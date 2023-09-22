#include "LinearModel.hpp"

LinearModel::LinearModel(double a, double b):
 a(a),
 b(b) {}

double LinearModel::get_a() { return a; }
double LinearModel::get_b() { return b; }

void LinearModel::set_a(double _a) { a = _a; }
void LinearModel::set_b(double _b) { b = _b; }

double LinearModel::simulate_temperature(double Yt, double Uw) {
    return a*Yt + b*Uw;
}