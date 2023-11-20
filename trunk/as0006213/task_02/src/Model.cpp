#include "model.h"

void Model::sync(double* arrStart) {
    this->u = arrStart[0];
    this->u_p = arrStart[1];
};

double Model::stepModelingNL(double u_n) {
    u_p = u;
    u = u_n;
    double y_n = (a * y - b * pow(y_p, 2) + c * u + d * sin(u_p));
    y_p = y;
    y = y_n;
    return y;
};
double Model::stepModelingL(double u_n) {
    u = u_n;
    double y_n = a * y - b * u;
    double y = y_n;
    return y;
};