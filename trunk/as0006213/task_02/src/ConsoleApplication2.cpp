#include "model.h"
#include "regulator.h"
#include <iostream>
#include <vector>

double sy1 = 20.0; 
double sy2 = 20.5;

int main()
{
    int num = 30;
    std::vector <double> u;
    //Генератор ПСЧ
    std::cout << "Natural temperature" << std::endl;
    for (int i = 0; i < num; i++) {
        u.push_back(20.0 - i / 5.0 + i * i / 9.0 - i * i * i / 260.0);
        std::cout << u[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "Nonlineal model" << std::endl;
    double arr_m1[4] = { 1, 0.01, 0.5, 0.7 };
    Model model1(arr_m1, sy1, sy2);
    double arr_aux1[2] = { u[0], u[1] };
    model1.sync(arr_aux1);//////////////////////////////////////////////////
    std::vector <double> vecMod1;
    vecMod1.push_back(sy1); std::cout << vecMod1.back() << "\t";
    vecMod1.push_back(sy2); std::cout << vecMod1.back() << "\t";
    for (int i = 2; i < u.size(); i++) {
        vecMod1.push_back(model1.stepModelingNL(u[i]));
        std::cout << vecMod1.back() << "\t";
    }
    std::cout << std::endl;

    std::cout << "Nonlineal model control" << std::endl;
    double arr1[4] = { 0.1, 0.09, 0.007, 0.001 };
    Regulator reg1(arr1, 20);
    double arr_aux2[3] = { 0, 0, 0 };
    reg1.sync(arr_aux2);
    std::vector <double> vecReg1;
    for (int i = 0; i < u.size(); i++) {
        vecReg1.push_back(reg1.step(vecMod1[i]));
        std::cout << vecReg1[i] << "\t";
    };
    std::cout << std::endl;

    std::cout << "Lineal model" << std::endl;
    double arr_m2[4] = { 1.15, 0.007, 0, 0 };
    Model model2(arr_m2, sy1, sy2);
    model1.sync(arr_aux1);
    std::vector <double> vecMod2;
    vecMod2.push_back(sy1); std::cout << vecMod2.back() << "\t";
    for (int i = 1; i < u.size(); i++) {
        vecMod2.push_back(model2.stepModelingNL(u[i]));
        std::cout << vecMod2.back() << "\t";
    }
    std::cout << std::endl;

    std::cout << "Lineal model control" << std::endl;
    double arr2[4] = { 0.6, 0.8, 0.1, 0.01 };
    Regulator reg2(arr2, 20);
    double arr_aux3[3] = { 15, 19, 18 };
    reg2.sync(arr_aux3);
    std::vector <double> vecReg2;
    for (int i = 0; i < u.size(); i++) {
        vecReg2.push_back(reg2.step(vecMod2[i]));
        std::cout << vecReg2[i] << "\t";
    };

};