#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//The Math_Model class is an abstract base class for mathematical models
class Math_Model {
public:
   virtual double calc_Output(double curOutput, double prevOutput, double input) const = 0;
   virtual ~Math_Model() = default;
};
//Класс Non_lin_Model является производным от Math_Model и представляет нелинейную математическую модель.- Коэффициенты coefficientA, coefficientB, coefficientC и coefficientD в классе Non_lin_Model используются для вычисления выходного значения модели на основе текущего значения, предыдущего значения и входного значения с помощью формулы coefficientA * currentOutput - coefficientB * pow(previousOutput, 2) + coefficientC * input + coefficientD * sin(input).
class Non_lin_Model : public Math_Model {
private:
    double coefA;
    double coefB;
    double coefC;
    double coefD;
public:
   Non_lin_Model(double coefA, double coefB, double coefC, double coefD)
        : coefA(coefA), coefB(coefB), coefC(coefC), coefD(coefD) {}
   double calc_Output(double curOutput, double prevOutput, double input) const override {
       return coefA*curOutput-coefB*pow(prevOutput,2)+coefC*input+coefD*sin(input);}};
//The Lin_Model class also derives from Math_Model and represents a linear mathematical model
class Lin_Model : public Math_Model {
private:
   double coefficientA;
   double coefficientB;
public:
   explicit Lin_Model(double coefficientA, double coefficientB) : coefficientA(coefficientA), coefficientB(coefficientB) {}
   double calc_Output(double currentOutput, double previousOutput, double input) const override {
       return coefficientA * currentOutput + coefficientB * input;}};
//The PID_Regulator class represents the implementation of a PID regulator. It contains the coefficients gainP, gainI and gainD, which correspond to the proportional, integral and differential components of the controller, respectively.
class PIDRegulator{
private:
   double P;
   double I;
   double D;
   double previousError = 0.0;
   double integralError = 0.0;
   double previousControlSignal = 0.0;
public:
   explicit PIDRegulator(double P, double I, double D)
        : P(P), I(I), D(D) {}
   double calcOutput(double currentError) {
       integralError += currentError;
       double derivativeError = currentError - previousError;
       double controlSignal = P * currentError + I * integralError + D * derivativeError;
       previousError = currentError;
       previousControlSignal = controlSignal;
       return controlSignal;}};
//In the main function, instances of models and the controller are created, and the necessary variables are declared and initialized
int main() {
     double coefA_linear = 0.7;
     double coefB_linear = 0.4;
     double coefA_nonlinear = 0.7;
     double coefB_nonlinear = 0.4;
     double coefC_nonlinear = 0.1;
     double coefD_nonlinear = 0.1;
     double currentOutput_linear = 0.0;
     double currentOutput_nonlinear = 0.0;
     double previousOutput_nonlinear = 0.0;
     double input = 1.0;
     Non_lin_Model nonlinModel(coefA_nonlinear, coefB_nonlinear, coefC_nonlinear, coefD_nonlinear);
     Lin_Model linModel(coefA_linear, coefB_linear);
     PIDRegulator pidRegulator(1.0, 0.5, 0.2);
     vector<double> curOutput_linear_values;
     vector<double> curOutput_nonlinear_values;
     vector<double> ervalues;
     vector<double> controlSig_values;
     for (int t = 1; t <= 10; t++) {
         currentOutput_linear = linModel.calc_Output(currentOutput_linear, 0, input);
         currentOutput_nonlinear = nonlinModel.calc_Output(currentOutput_nonlinear, previousOutput_nonlinear, input);
         previousOutput_nonlinear = currentOutput_nonlinear;

         double error = currentOutput_linear - currentOutput_nonlinear;
         double controlSignal = pidRegulator.calcOutput(error);

         curOutput_linear_values.push_back(currentOutput_linear);
         curOutput_nonlinear_values.push_back(currentOutput_nonlinear);
         ervalues.push_back(error);
         controlSig_values.push_back(controlSignal);
     } // After the loop, the results for each iteration are printed, including the model outputs, the error, and the control signal
     for (int t = 0; t < 10; t++) {
         cout << "Iteration " << t + 1 << ":\n";
         cout << "Linear model output: " << curOutput_linear_values[t] << '\n';
         cout << "Nonlinear model output: " << curOutput_nonlinear_values[t] << '\n';
         cout << "ERROR: " << ervalues[t] << '\n';
         cout << "Control signal: " << controlSig_values[t] << '\n';
         cout << '\n';}
     return 0;
}