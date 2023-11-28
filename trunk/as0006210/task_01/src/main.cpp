#include <iostream>
#include <cmath>

class Model {
public:
    virtual ~Model() = default;
    virtual double simulate_temperature(double Yt, double Uw) = 0;
};

class LinearModel : public Model {
private:
    double a;
    double b;
public:
    LinearModel(double a, double b) : a(a), b(b) {}

    virtual ~LinearModel() = default;

    double simulate_temperature(double Yt, double Uw) override {
        return a * Yt + b * Uw;
    }
};

class NonlinearModel : public Model {
private:
    double a;
    double b;
    double c;
    double d;
    double PreYt = 0;
    double PreUw = 0;
public:
    NonlinearModel(double a, double b, double c, double d) :
        a(a),
        b(b),
        c(c),
        d(d) {}

    virtual ~NonlinearModel() = default;

    double simulate_temperature(double Yt, double Uw) override {
        double calc = a * Yt - b * pow(PreYt, 2) + c * Uw + d * sin(PreUw);
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

    std::cout << "---Please input LinearModel's constant parameters--- " << std::endl;
    std::cout << "Input a-parameter: ";
    std::cin >> a;
    std::cout << "Input b-parameter: ";
    std::cin >> b;

    LinearModel linear_model{ a,b };

    std::cout << "---Please input NonlinearModel's constant parameters--- " << std::endl;
    std::cout << "Input a-parameter: ";
    std::cin >> a;
    std::cout << "Input b-parameter: ";
    std::cin >> b;
    std::cout << "Input c-parameter: ";
    std::cin >> c;
    std::cout << "Input d-parameter: ";
    std::cin >> d;

    NonlinearModel nonlinear_model{ a,b,c,d };

    std::cout << "Please input Yt-parameter: ";
    std::cin >> Yt;

    std::cout << "Please input number of time modeling for the LinearModel: ";
    std::cin >> numOfTimeModeling;

    //start simulating an object temperature

    std::cout << "\t\t\t---LinearModel---" << std::endl;
    std::cout << "\t\t\tMoments\t\tYt\n";
    modeling(linear_model, Yt, static_cast<int>(numOfTimeModeling));

    std::cout << std::endl;

    std::cout << "Please input number of time modeling for the NonlinearModel: ";
    std::cin >> numOfTimeModeling;
    std::cout << "\t\t\t---NonlinearModel---" << std::endl;
    std::cout << "\t\t\tMoments\t\tYt\n";
    modeling(nonlinear_model, Yt, static_cast<int>(numOfTimeModeling));
}