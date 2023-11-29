

#include "tmau1_c_mk.h"


void Linear(double a, double b, double current_temperature, double input_warm, size_t itterations) {


    for (size_t i = 0; i < itterations; i++)
    {
        double next = a * current_temperature + b * input_warm;
        std::cout << next << "\n";
        current_temperature = next;
    }
    std::cout << "end\n";

}

void NonLinear(double a, double b, double c, double d, double current_temperature, double input_warm, size_t itterations) {

    double previous_temperature = 0;
    for (size_t i = 0; i < itterations; i++)
    {
        double next = a * current_temperature - b * previous_temperature * previous_temperature + c * input_warm + d * sin(input_warm);
        previous_temperature = current_temperature;
        current_temperature = next;
        std::cout << next << "\n";
    }
    std::cout << "end\n";


}

int main()
{
    double a;
double b;
double c; 
double d; 
double current_temperature; 
double input_warm;
    bool mode;
    size_t itterations;
    std::cout << "A: ";
    std::cin >> a;
    std::cout << "B: ";
    std::cin >> b;
    std::cout << "C: ";
    std::cin >> c;
    std::cout << "D: ";
    std::cin >> d;
    std::cout << "Current temperature: ";
    std::cin >> current_temperature;
    std::cout << "Input warm: ";
    std::cin >> input_warm;
    std::cout << "Mode (1 - linear, 0 - NonLinear): ";
    std::cin >> mode;
    std::cout << "How many itterations: ";
    std::cin >> itterations;

    if (mode)
        Linear(a, b, current_temperature, input_warm, itterations);
    else
        NonLinear(a, b, c, d, current_temperature, input_warm, itterations);

}

