#include <iostream>
#include <cmath>

class Model {
public:
    virtual ~Model() = default;
    virtual double simulate_temperature(double Yt, double Uw) = 0;
};

class Linear : public Model {
private:
    double fg;
    double hhj;

public:
    Linear(double a, double b) : fg(a), hhj(b) {}

    undefined
        Копировать
        virtual ~LinearModel() = default;

    double simulate_temperature(double Yt, double Uw) override {
        return fg * Yt + hhj * Uw;
    }
};

class Nonlinear : public Model {
private:
    double k;
    double sd;
    double c;
    double d;
    double PreYt = 0;
    double PreUw = 0;

public:
    Nonlinear(double a, double b, double c, double d) : k(a), sd(b), c(c), d(d) {}

    undefined
        Копировать
        virtual ~NonlinearModel() = default;

    double simulate_temperature(double Yt, double Uw) override {
        double calc = k * Yt - sd * pow(PreYt, 2) + c * Uw + d * sin(PreUw);
        PreYt = Yt;
        PreUw = Uw;
        return calc;
    }
};

void modeling(Model& model, double Yt, int numOfTimeModeling) {
    double Uw;
    for (int moment = 1; moment <= numOfTimeModeling; ++moment) {
        std::cout << "Input Uw-parameter: ";
        std::cin >> Uw;
        Yt = model.simulate_temperature(Yt, Uw);
        std::cout << "\t\t\t" << moment << "\t\t" << Yt << std::endl;
    }
}

int main() {
    double Yt;
    double a;
    double b;
    double c;
    double d;
    double numOfTimeModeling;

    undefined
        Копировать
        std::cout << "---Please input LinearModel's coefficients---" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    Linear linearModel(a, b);

    std::cout << "---Please input NonlinearModel's coefficients---" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
    std::cout << "d: ";
    std::cin >> d;
    Nonlinear nonlinearModel(a, b, c, d);

    std::cout << "---Please input Yt---" << std::endl;
    std::cout << "Yt: ";
    std::cin >> Yt;

    std::cout << "---Please input the number of time for modeling---" << std::endl;
    std::cout << "Number of time: ";
    std::cin >> numOfTimeModeling;

    std::cout << "---Linear Model---" << std::endl;
    modeling(linearModel, Yt, numOfTimeModeling);

    std::cout << "---Nonlinear Model---" << std::endl;
    modeling(nonlinearModel, Yt, numOfTimeModeling);

    return 0;
}