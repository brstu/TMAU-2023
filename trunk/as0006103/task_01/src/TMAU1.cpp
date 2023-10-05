#include <iostream>
#include <cmath>

class Object {
public:
    virtual ~Object() = default;
    virtual double ModelFunction(double Yt, double Ut) = 0;
};
class NotModelLiner : public Object
{
public:
    double a;
    double b;
    double prev_ut = 0;
    double prev_yt = 0;
    double c;
    double d;
    NotModelLiner(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
    ~NotModelLiner() = default;
    double ModelFunction (double yt, double ut) {
        return a * yt - b * pow(prev_yt, 2) + c * ut + d * sin(prev_ut);
    }
    void OutputModel(double y, double u, int NotNumLin)
    {
        double Yt = y;
        double Ut = u;

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

class ModelLiner : public Object
{
public:
    double a;
    double b;
    ModelLiner(double a, double b) : a(a), b(b) {}
    ~ModelLiner() = default;
    double ModelFunction (double yt, double ut) {
        return a * yt + b * ut;
    }
    void OutputModel(double y, double u, int NumLin)
    {
        double Yt = y;
        double Ut = u;
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
    double y = 0;
    double u = 0;
    double bLiner = 0;
    double aLiner = 0;
    double bNotLiner = 0;
    double aNotLiner = 0;
    double c = 0;
    double d = 0;
    int NumLin = 0;
    int NumNotLin = 0;
    std::cout << "Number of iteration" << std::endl;
    EnterValue(NumLin, "Liner Model:");
    std::cout << "Liner Model:";
    std::cin >> NumLin;

    std::cout << "Not Liner Model:";
    std::cin >> NumNotLin;
    std::cout << "enter value y:";
    std::cin >> y;
    std::cout << "enter value u:";
    std::cin >> u;

    std::cout << std::endl << "Liner model" << std::endl;
    std::cout << "enter value a:";
    std::cin >> aLiner;
    std::cout << "enter value b:";
    std::cin >> bLiner;

    std::cout << std::endl << "Not liner model" << std::endl;
    std::cout << "enter value a:";
    std::cin >> aNotLiner;
    std::cout << "enter value b:";
    std::cin >> bNotLiner;
    std::cout << "enter value c:";
    std::cin >> c;
    std::cout << "enter value d:";
    std::cin >> d;
    ModelLiner modelLin(aLiner, bLiner);
    modelLin.OutputModel(y, u, NumLin);
    NotModelLiner notmodelLin(aNotLiner, bNotLiner, c, d);
    notmodelLin.OutputModel(y, u, NumLin);

}