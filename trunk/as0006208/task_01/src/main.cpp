﻿#include <iostream>
#include <cmath>
using namespace std;

double linModel(double Yt, double U, double a, double b) {
    return a * Yt + b * U;
}

double nlModel(double Yt, double Yt_1, double U, double a, double b, double c, double d) {
    return a * Yt - b * pow(Yt_1, 2) + c * U + d * sin(U);
}

int main() {

    
    double a_nl = 0.9;
    double b_nl = 0.5;
    double c_nl = 0.6;
    double d_nl = 0.4;

    double a_lin = 0.3;
    double b_lin = 0.7;


    double Y_lin = 0.0;
    double Y_nl = 0.0;
    double Y_prev_nl = 0.0;

    
    double U = 1.0;

    
    for (int t = 1; t <= 10; t++) {
        
        Y_lin = linModel(Y_lin, U, a_lin, b_lin);

        Y_nl = nlModel(Y_nl, Y_prev_nl, U, a_nl, b_nl, c_nl, d_nl);
        Y_prev_nl = Y_nl;

         cout << "time step: " << t <<  endl;
         cout << "lin model: " << Y_lin <<  endl;
         cout << "nl model: " << Y_nl <<  endl;
         cout << "------------------------" <<  endl;
    }

    return 0;
}