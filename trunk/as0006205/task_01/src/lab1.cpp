#include <iostream>
#include <cmath>

class Model{
public:
 virtual ~Model() = default;
 virtual double simulate_temperature(double Yt, double Uw) = 0;
};

class LinearModel : public Model {
private:
    double g;
    double h;
public:
    LinearModel(double g, double h): g(g), h(h) {}

    virtual LinearModel() = default;
    
    double simulate_temperature(double Yt, double Uw) final {
        return g*Yt + h*Uw;
    }
};

class NonlinearModel : public Model {
private:
    double g;
    double h;
    double j;
    double k;
    double PreYt = 0;
    double PreUw = 0;
public:
    NonlinearModel(double g, double h, double j, double k):
        g(g),
        h(h),
        j(j),
        k(k) {}

    virtual NonlinearModel() = default;
    
    double simulate_temperature(double Yt, double Uw) final {
        double calc = g*Yt - h*pow(PreYt, 2) + j*Uw + k*sin(PreUw);
        PreYt = Yt;
        PreUw = Uw;
        return calc;
    }
};

void modeling(Model& model, double Yt, int numOfTimeModeling) {
    double Uw;
    for(int moment = 1; moment <= numOfTimeModeling; ++moment) {
        std::cout << "Input Uw-parameter: "; std::cin >> Uw;
        Yt = model.simulate_temperature(Yt, Uw);

        std::cout << "\t\t\t" << moment << "\t\t" << Yt << std::endl; 
    }
}

int main() {
    double YT1;
    double g;
    double h;
    double j;
    double k;
    double numOfTimeModeling;

    std::cout << "---Please input LinearModel's constant parameters--- " << std::endl;
    std::cout << "Input a-parameter: "; std::cin >> g;
    std::cout << "Input b-parameter: "; std::cin >> h;
    
    LinearModel linear_model{j,h};

    std::cout << "---Please input NonlinearModel's constant parameters--- " << std::endl;
    std::cout << "Input a-parameter: "; std::cin >> g;
    std::cout << "Input b-parameter: "; std::cin >> h;
    std::cout << "Input c-parameter: "; std::cin >> j;
    std::cout << "Input d-parameter: "; std::cin >> k;
    
    NonlinearModel nonlinear_model{g,h,j,k};

    std::cout << "Please input Yt-parameter: "; std::cin >> YT1;
    
    std::cout << "Please input number of time modeling for the LinearModel: ";
    std::cin >> numOfTimeModeling;

    //start simulating an object temperature

    std::cout << "\t\t\t---LinearModel---" << std::endl;
    std::cout << "\t\t\tMoments\t\tYt\n";
    modeling(linear_model, YT1, static_cast<int>(numOfTimeModeling));

    std::cout << std::endl;
    
    std::cout << "Please input number of time modeling for the NonlinearModel: ";
    std::cin >> numOfTimeModeling;
    std::cout << "\t\t\t---NonlinearModel---" << std::endl;
    std::cout << "\t\t\tMoments\t\tYt\n";
    modeling(nonlinear_model, YT1, static_cast<int>(numOfTimeModeling ));

    system("Pause");
}
