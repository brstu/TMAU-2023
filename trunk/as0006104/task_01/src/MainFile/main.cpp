#include <iostream>
#include "LinearModel.hpp"
#include "NonlinearModel.hpp"

int main() {
    double Yt, PreYt, Uw, PreUw, a, b, c, d;
    double numOfTimeModeling;

    std::cout << "---Please input LinearModel's constant parameters--- " << std::endl;
    std::cout << "Input a-parameter: "; std::cin >> a;
    std::cout << "Input b-parameter: "; std::cin >> b;
    
    LinearModel linear_model{a,b};

    std::cout << "---Please input NonlinearModel's constant parameters--- " << std::endl;
    std::cout << "Input a-parameter: "; std::cin >> a;
    std::cout << "Input b-parameter: "; std::cin >> b;
    std::cout << "Input c-parameter: "; std::cin >> c;
    std::cout << "Input d-parameter: "; std::cin >> d;
    
    NonlinearModel nonlinear_model{a,b,c,d};

    std::cout << "Please input Yt-parameter: "; std::cin >> Yt;
    double save_yt = Yt; 
    
    std::cout << "Please input number of time modeling for the LinearModel: ";
    std::cin >> numOfTimeModeling;

    //start simulating an object temperature

    std::cout << "\t\t\t---LinearModel---" << std::endl;
    std::cout << "\t\t\tMoments\t\tYt\n";
    for(int moment = 1; moment <= numOfTimeModeling; ++moment) {
        std::cout << "Input Uw-parameter: "; std::cin >> Uw;
        Yt = linear_model.simulate_temperature(Yt, Uw);

        std::cout << "\t\t\t" << moment << "\t\t" << Yt << std::endl; 
    }
    std::cout << std::endl;
    std::cout << "Please input number of time modeling for the NonlinearModel: ";
    std::cin >> numOfTimeModeling;
    std::cout << "\t\t\t---NonlinearModel---" << std::endl;
    Yt = save_yt;
    std::cout << "\t\t\tMoments\t\tYt\n";
    for(int moment = 1; moment <= numOfTimeModeling; ++moment) {
        if(moment > 1) {
            PreUw = Uw;
        }
        else {
            PreYt = 0;
            PreUw = 0;
        }

        std::cout << "Input Uw-parameter: "; std::cin >> Uw;
        Yt = nonlinear_model.simulate_temperature(Yt, PreYt, Uw, PreUw);
        PreYt = save_yt;
        save_yt = Yt;
     
         std::cout << "\t\t\t" << moment << "\t\t" << Yt << std::endl;
    }
    system("Pause");
}