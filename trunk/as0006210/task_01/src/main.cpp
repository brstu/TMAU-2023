#include <iostream>
#include <cmath>
#include <functional>

// Define a type alias for readability
using SimulationFunction = std::function<double(double, double)>;

class Model {
public:
    virtual ~Model() = default;
    virtual double simulate_temperature(double Yt, double Uw) const = 0;
};

class LinearModel : public Model {
    double a;
    double b;
public:
    LinearModel(double aParam, double bParam) : a(aParam), b(bParam) {}

    double simulate_temperature(double Yt, double Uw) const override {
        return a * Yt + b * Uw;
    }
};

class NonlinearModel : public Model {
    double a;
    double b;
    double c;
    double d;
    mutable double lastYt = 0;
    mutable double lastUw = 0;
public:
    NonlinearModel(double aParam, double bParam, double cParam, double dParam) :
        a(aParam), b(bParam), c(cParam), d(dParam) {}

    double simulate_temperature(double Yt, double Uw) const override {
        double output = a * Yt - b * std::pow(lastYt, 2) + c * Uw + d * std::sin(lastUw);
        lastYt = Yt;
        lastUw = Uw;
        return output;
    }
};

class SimulationEnvironment {
public:
    void perform_simulation(const Model& model, double Yt, int numOfIterations) const {
        double userParam;
        for (auto iteration = 0; iteration < numOfIterations; ++iteration) {
            std::cout << "Enter external parameter Uw: ";
            std::cin >> userParam;
            Yt = model.simulate_temperature(Yt, userParam);

            std::cout << "\tTime: " << iteration + 1 << "\tTemperature: " << Yt << std::endl;
        }
    }
};

int main() {
    double Yt, a, b, c, d;
    int numOfIterations;

    std::cout << "--- Configure Linear Model ---\n";
    std::cout << "Enter parameter a: "; std::cin >> a;
    std::cout << "Enter parameter b: "; std::cin >> b;
    LinearModel linearModel(a, b);

    std::cout << "--- Configure Nonlinear Model ---\n";
    std::cout << "Enter parameter a: "; std::cin >> a;
    std::cout << "Enter parameter b: "; std::cin >> b;
    std::cout << "Enter parameter c: "; std::cin >> c;
    std::cout << "Enter parameter d: "; std::cin >> d;
    NonlinearModel nonlinearModel(a, b, c, d);

    std::cout << "Enter initial temperature Yt: "; std::cin >> Yt;

    SimulationEnvironment simulationEnvironment;

    std::cout << "Enter the number of iterations for Linear Model: ";
    std::cin >> numOfIterations;
    std::cout << "--- Simulating Linear Model ---\n";
    simulationEnvironment.perform_simulation(linearModel, Yt, numOfIterations);

    std::cout << "\nEnter the number of iterations for Nonlinear Model: ";
    std::cin >> numOfIterations;
    std::cout << "--- Simulating Nonlinear Model ---\n";
    simulationEnvironment.perform_simulation(nonlinearModel, Yt, numOfIterations);

    std::cout << "Simulation complete.\n";
    // The system("Pause") command is not recommended; this is for Windows only.
    std::cin.get(); // To pause the output instead of system("Pause")
    std::cin.get(); // This is to catch any extra newline input to prevent closing immediately.
    return 0;
}