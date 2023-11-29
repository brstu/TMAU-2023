// CMake_TM1.cpp: определяет точку входа для приложения.
//

#include "CMake_TM1.h"

#include <cmath>


class TemperatureCalculator
{
public:
    virtual double CalculateNextTemperature(double input_warm) = 0;
protected:
    TemperatureCalculator() {};
};


class LinearTemperatureCalculator : public TemperatureCalculator
{
private:
    double a;
    double b;
    double current_temperature;
public:
    LinearTemperatureCalculator(double current_temperature, double a, double b)
    {
        this->a = a;
        this->b = b;
        this->current_temperature = current_temperature;
    }

    virtual double CalculateNextTemperature(double input_warm)
    {
        this->current_temperature = this->a * this->current_temperature + this->b * input_warm;
        return current_temperature;
    }
};


class NonlinearTemperatureCalculator : public TemperatureCalculator
{
private:
    double a;
    double b;
    double c;
    double d;
    double current_temperature, previous_temperature;
public:
    NonlinearTemperatureCalculator(double current_temperature, double a, double b, double c, double d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->current_temperature = current_temperature;
        this->previous_temperature = 0.0;
    }

    virtual double CalculateNextTemperature(double input_warm)
    {
        double buffer_temperature = this->current_temperature;
        this->current_temperature = this->a * this->current_temperature - this->b * this->previous_temperature * this->previous_temperature + this->c * input_warm + this->d * sin(input_warm);
        this->previous_temperature = buffer_temperature;
        return this->current_temperature;
    }
};


class TemperatureViewer
{
private:
    TemperatureCalculator* _temperature_calculator;
public:
    TemperatureViewer(TemperatureCalculator* temperature_calculator)
    {
        _temperature_calculator = temperature_calculator;
    }

    void GetTemperaturesToConsole(int iterations_number, double input_warm)
    {
        for (int i = 0; i < iterations_number; i++) {
            std::cout << _temperature_calculator->CalculateNextTemperature(input_warm) << std::endl;
        }
    }

    ~TemperatureViewer()
    {
        delete _temperature_calculator;
    }
};


int main()
{
    TemperatureViewer* temperature_viewer;
    double a;
    double b;
    double c;
    double d;
    double current_temperature;
    int choise;
    std::cout << "Choose calculate strategy (0 - linear, 1 - nonlinear):" << std::endl;
    std::cin >> choise;

    switch (choise) {
    case 0:
    {
        std::cout << "Linear mode \n";
        std::cout << "Input A: ";
        std::cin >> a;
        std::cout << "Input B: ";
        std::cin >> b;
        std::cout << "Input Current temperature: ";
        std::cin >> current_temperature;
        TemperatureCalculator* linear_temperature_calculator = new LinearTemperatureCalculator(current_temperature, a, b);
        temperature_viewer = new TemperatureViewer(linear_temperature_calculator);
        double input_warm;
        int iterations_number;
        std::cout << "Input warm: ";
        std::cin >> input_warm;
        std::cout << "Iterations count: ";
        std::cin >> iterations_number;
        temperature_viewer->GetTemperaturesToConsole(iterations_number, input_warm);
        delete temperature_viewer;
        break;
    }
    case 1:
    {
        std::cout << "NonLinear mode \n";
        std::cout << "Input A: ";
        std::cin >> a;
        std::cout << "Input B: ";
        std::cin >> b;
        std::cout << "Input C: ";
        std::cin >> c;
        std::cout << "Input D: ";
        std::cin >> d;
        std::cout << "Input Current temperature: ";
        std::cin >> current_temperature;
        TemperatureCalculator* nonlinear_temperature_calculator = new NonlinearTemperatureCalculator(current_temperature, a, b, c, d);
        temperature_viewer = new TemperatureViewer(nonlinear_temperature_calculator);
        double input_warm;
        int iterations_number;
        std::cout << "Input warm: ";
        std::cin >> input_warm;
        std::cout << "Iterations count: ";
        std::cin >> iterations_number;
        temperature_viewer->GetTemperaturesToConsole(iterations_number, input_warm);
        delete temperature_viewer;
        break;
    }
    default:
        break;
    }


    return 0;
}