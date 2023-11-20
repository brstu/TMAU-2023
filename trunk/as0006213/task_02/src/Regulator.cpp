#include "regulator.h"

void Regulator::sync(double* arrStart) {
	this->ek = arrStart[0];
	this->ek_p = arrStart[1];
	this->ek_pp = arrStart[2];
};

void Regulator::defConstants() {
	this->q0 = K * (1 + Td / T0);
	this->q1 = -K * (1 + 2 * Td / T0 - T0 / T);
	this->q2 = K * Td / T0;
};

double Regulator::deltaU() {
	return(q0 * ek + q1 * ek_p + q2 * ek_pp);
};

double Regulator::step(double ek_n) {
	ek_pp = ek_p;
	ek_p = ek;
	ek = ek_n;
	double u = u_p + deltaU();
	u_p = u;
	return u;
};