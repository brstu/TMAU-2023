#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <stdlib.h>

class Model {
private:
    double a;
    double b;
    double c;
    double d;
    std::vector <double> u;
    std::stack <double> y;
public:
    explicit Model(const std::vector <double>& u) {
        setConstants(0, 0, 0, 0);
        y.push(20.0);
        y.push(20.0);
        setU(u);
    }
    void setU(std::vector <double> newU) {
        newU.push_back(20.0);
        for (double i : newU) {
            this->u.push_back(i);
        }
    }
    void setConstants(double newA, double newB, double newC, double newD) {
        this->a = newA;
        this->b = newB;
        this->c = newC;
        this->d = newD;
    }
    void stepModelingNL(int i) {
        i += 1;
        double yPrev = y.top();
        y.pop();
        double yPPrev = y.top();
        y.push(yPrev);
        y.push(a * yPrev - b * pow(yPPrev, 2) + c * u[i] + d * sin(u[i - 1]));
    }
    void stepModelingL(int i) {
        double yNext = a * y.top() - b * u[i];
        y.push(yNext);
    }
    double getY() { 
        return y.top(); 
    }
};

int main()
{
    int num = 30;
    std::vector <double> u;
    //Генератор случайных чисел
    for (int i = 0; i < num; i++) {
        u.push_back(20.0 - i / 5.0 + i * i / 9.0 - i * i * i / 260.0);
        std::cout << u[i] << "\t";
    }
    std::cout << std::endl;
    Model model1(u);
    //Нелинейная модель
    model1.setConstants(1, 0.01, 0.5, 0.7); //Набор констант подобран вручную
    for (int i = 0; i < u.size(); i++) {
        model1.stepModelingNL(i);
        std::cout << model1.getY() << "\t";
    }
    std::cout << std::endl;
    //Линейная модель
    Model model2(u);
    model2.setConstants(1.15, 0.134, 0, 0); //Набор констант подобран вручную
    for (int i = 0; i < u.size(); i++) {
        model2.stepModelingL(i);
        std::cout << model2.getY() << "\t";
    }
};