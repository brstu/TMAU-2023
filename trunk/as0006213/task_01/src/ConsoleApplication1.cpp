#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <stdlib.h>

class Model {
private:
    float a, b, c, d;
    std::vector <float> u;
    std::stack <float> y;
public:
    Model(std::vector <float> u) {
        setConstants(0, 0, 0, 0);
        y.push(20.0);
        y.push(20.0);
        setU(u);
    };
    void setU(std::vector <float> u) {
        u.push_back(20.0);
        for (int i = 0; i < u.size(); i++) {
            this->u.push_back(u[i]);
        };
    };
    void setConstants(float a, float b, float c, float d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    };
    void stepModelingNL(int i) {
        i += 1;
        float yPrev = y.top();
        y.pop();
        float yNext = a * yPrev - b * pow(y.top(), 2) + c * u[i] + d * sin(u[i-1]);
        y.push(yPrev);
        y.push(yNext);
    };
    void stepModelingL(int i) {
        float yNext = a * y.top() - b * u[i];
        y.push(yNext);
    };
    float getY() {return y.top(); };
};

int main()
{
    int num = 30;
    std::vector <float> u;
    //Генератор случайных чисел
    for (int i = 0; i < num; i++) {
        u.push_back(20.0 - i / 5.0 + i * i / 9.0 - i * i * i / 260.0);
        std::cout << u[i] << "\t";
    };
    std::cout << std::endl;
    Model model1(u);
    //Нелинейная модель
    model1.setConstants(1, 0.01, 0.5, 0.7); //Набор констант подобран вручную
    for (int i = 0; i < u.size(); i++) {
        model1.stepModelingNL(i);
        std::cout << model1.getY() << "\t";
    };
    std::cout << std::endl;
    //Линейная модель
    Model model2(u);
    model2.setConstants(1.15, 0.133, 0, 0); //Набор констант подобран вручную
    for (int i = 0; i < u.size(); i++) {
        model2.stepModelingL(i);
        std::cout << model2.getY() << "\t";
    };
};