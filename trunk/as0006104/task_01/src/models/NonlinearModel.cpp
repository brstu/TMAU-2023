#include "NonlinearModel.hpp"
#include <cmath>

NonlinearModel::NonlinearModel(double a, double b, double c, double d):
 a(a),
 b(b),
 c(c),
 d(d) {}

double NonlinearModel::get_a() { return a; }
double NonlinearModel::get_b() { return b; }
double NonlinearModel::get_c() { return c; }
double NonlinearModel::get_d() { return d; }

void NonlinearModel::set_a(double _a) { a = _a; }
void NonlinearModel::set_b(double _b) { b = _b; }
void NonlinearModel::set_c(double _c) { c = _c; }
void NonlinearModel::set_d(double _d) { d = _d; }

double NonlinearModel::simulate_temperature(double Yt, double PreYt, double Uw, double PreUw) {
    return a*Yt - b*pow(PreYt, 2) + c*Uw + d*sin(PreUw);
}