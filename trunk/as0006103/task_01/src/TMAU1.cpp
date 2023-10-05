#include <iostream>
#include <cmath>
template<typename Type>


void EnterValue(Type& value, std::string nameValue)
{
    std::cout << nameValue;
    std::cin >> value;
}
class Object {
public:
    virtual ~Object() = default;
    virtual double ModelFunction(double Yt, double Ut) = 0;
};
class NotModelLiner : Object
{
public:
    double a;
    double b;
    double prev_ut = 0;
    double prev_yt = 0;
    double c;
    double d;
    NotModelLiner(double a, double b, double c, double d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    ~NotModelLiner() = default;
    double ModelFunction(double yt, double ut) {
        return a * yt - b * pow(prev_yt, 2) + c * ut + d * sin(prev_ut);
    }
    void OutputModel(double y, double u, int NotNumLin)
    {
        double Yt = y, Ut = u;

        std::cout << std::endl << std::endl << "Not liner model";
        std::cout << "\t\t\tIteration number:" << "\t\t\t" << "Yt";
        for (int i = 0; i < NotNumLin; i++) {
            if (i > 0) {
                prev_ut = Ut, prev_yt = Yt;
                std::cout << std::endl;
                EnterValue(Ut, "enter value Ut:");
                Yt = ModelFunction(Yt, Ut);
                std::cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
            }
            else {
                prev_ut = 0; prev_yt = 0;
                std::cout << std::endl;
                EnterValue(Ut, "enter value Ut:");
                Yt = ModelFunction(Yt, Ut);
                std::cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
            }
        }

    }
};

class ModelLiner : Object
{
public:
    double a;
    double b;
    ModelLiner(double a, double b) {
        this->a = a;
        this->b = b;
    }
    ~ModelLiner() = default;
    double ModelFunction(double yt, double ut) {
        return a * yt + b * ut;
    }
    void OutputModel(double y, double u, int NumLin)
    {
        double Yt = y, Ut = u;
        std::cout << std::endl << std::endl << "Liner model";
        std::cout << "\t\t\tIteration number:" << "\t\t\t" << "Yt";
        for (int i = 0; i < NumLin; i++) {
            std::cout << std::endl;
            EnterValue(Ut, "enter value Ut:");

            Yt = ModelFunction(Yt, Ut);
            std::cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
        }
    }
};


int main()
{
    double y = 0, u = 0, bLiner = 0, aLiner = 0, bNotLiner = 0, aNotLiner = 0, c = 0, d = 0;
    int NumLin = 0, NumNotLin = 0;
    std::cout << "Number of iteration" << std::endl;
    EnterValue(NumLin, "Liner Model:");
    EnterValue(NumNotLin, "Not Liner Model:");

    EnterValue(y, "enter value y:");
    EnterValue(u, "enter value u:");

    std::cout << std::endl << "Liner model" << std::endl;
    EnterValue(aLiner, "enter value a:");
    EnterValue(bLiner, "enter value b:");

    std::cout << std::endl << "Not liner model" << std::endl;
    EnterValue(aNotLiner, "enter value a:");
    EnterValue(bNotLiner, "enter value b:");
    EnterValue(c, "enter value c:");
    EnterValue(d, "enter value d:");

    ModelLiner modelLin(aLiner, bLiner);
    modelLin.OutputModel(y, u, NumLin);
    NotModelLiner notmodelLin(aNotLiner, bNotLiner, c, d);
    notmodelLin.OutputModel(y, u, NumLin);

}