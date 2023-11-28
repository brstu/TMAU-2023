// tmau1_c_make.cpp: определяет точку входа для приложения.
//

#include "tmau1_c_make.h"

int main()
{
    double a, b, c, d, current_temperature, input_warm;
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
    {
        for (size_t i = 0; i < itterations; i++)
        {
            double next = a * current_temperature + b * input_warm;
            std::cout << next << "\n";
            current_temperature = next;
        }
        std::cout << "end\n";
    }

    else
    {
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

}

