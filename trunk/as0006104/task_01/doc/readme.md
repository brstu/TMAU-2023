# Laboratory work №.1              
              MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                          EDUCATIONAL INSTITUTION 
                    «BREST STATE TECHNICAL UNIVERSITY»        
                            Department of IIT




                           Laboratory work №.1 



	                                	Completed by the 3rd year student of 
                                        the Faculty of Electronic Information Systems
	                                	the group AC-61 Dzibuk A.V.
                                 		Checked by Ivanuk D.S.



                                Brest 2023

## Task 1. Modeling controlled object: 
Write program (C++), which simulate object temperature.

### *Directory models:*

##### LinearModel.hpp
```C++
class LinearModel {
private:
    double a, b;
public:
    LinearModel(double a, double b);
    
    double get_a();
    double get_b();

    void set_a(double _a);
    void set_b(double _b);
    
    double simulate_temperature(double Yt, double Uw);
};
```

##### LinearModel.cpp
```C++
#include "LinearModel.hpp"

LinearModel::LinearModel(double a, double b):
 a(a),
 b(b) {}

double LinearModel::get_a() { return a; }
double LinearModel::get_b() { return b; }

void LinearModel::set_a(double _a) { a = _a; }
void LinearModel::set_b(double _b) { b = _b; }

double LinearModel::simulate_temperature(double Yt, double Uw) {
    return a*Yt + b*Uw;
}
```

##### NonlinearModel.hpp
```C++
class NonlinearModel {
private:
    double a, b, c, d;
public:
    NonlinearModel(double a, double b, double c, double d);
    
    double get_a();
    double get_b();
    double get_c();
    double get_d();

    void set_a(double _a);
    void set_b(double _b);
    void set_c(double _c);
    void set_d(double _d);

    double simulate_temperature(double Yt, double PreYt, double Uw, double PreUw);
};
```
##### NonlinearModel.cpp
```C++
#include "NonlinearModel.hpp"
#include <cmath>

NonlinearModel::NonlinearModel(double a, double b, double c, double d):
 a(a),
 b(b),
 c(c),
 d(d) {}

double NonlinearModel::get_a() { return a; }
double NonlinearModel::get_b() { return b; }
double NonlinearModel::get_c() { return c; }
double NonlinearModel::get_d() { return d; }

void NonlinearModel::set_a(double _a) { a = _a; }
void NonlinearModel::set_b(double _b) { b = _b; }
void NonlinearModel::set_c(double _c) { c = _c; }
void NonlinearModel::set_d(double _d) { d = _d; }

double NonlinearModel::simulate_temperature(double Yt, double PreYt, double Uw, double PreUw) {
    return a*Yt - b*pow(PreYt, 2) + c*Uw + d*sin(PreUw);
}
```

### *Directory MainFile:*
##### Main.cpp
```C++
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
```
<center style="font-size:30px;font-weight: bold">
RESULTS</center>

<center><img style='border:4px solid #000000'src="result.png"/></center>

### How to build the project?

1. The first you need to clone this repository to your computer.

2. Go to the folder "trunk\as0006104\task_01\src".

3. Run the command line and type 6 commands :

```console 
mkdir build
cd build
cmake ..
cmake --build .
cd MainFile\Debug
.\Main.exe
```



