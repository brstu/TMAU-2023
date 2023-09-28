#include <iostream>
#include <cmath>

int n = 16;

double linearModel (double y[16], double u, double a, double b){
    double newTemp [n];

    for (int i = 1; i < n; i++)
    {
        y[i] = a * y[i - 1] + b * u;
        newTemp[i] = y[i]; 
    }
     
    // Print the results for linear model
    std::cout << "For linear model:\n";
    for (int i = 1; i < n; i++) std::cout << "y["<< i <<"] = " << newTemp[i] << " \n";
    
    return 0;
}

double nonLinearModel(double y[16], double u, double a, double b, double c, double d){
    double newTemp2 [n];

    for (int i = 2; i < n; i++)
    {
        y[i] = a * y[i - 1] - b * y[i - 2] + c * u + d * sin(u);
        newTemp2[i] = y[i];
    }
    
    // Print the results for linear model
    std::cout << "For nonlinear model:\n";
    for (int i = 2; i < n; i++) std::cout << "y["<< i <<"] = " << newTemp2[i] << " \n";

    return 0;
}

int main(){
    double a = 1.2;
    double b = -0.4;
    double c = 0.6;
    double d = -0.2;
    double y[16];
    double u;
    


    std::cout << "input temperature"; 
    std::cin >> y[0];
    std::cout << "input warm"; 
    std::cin >> u;

    linearModel (y, u, a, b);
    nonLinearModel (y, u, a, b, c, d);


}
