#include <iostream>
#include <cmath>

double NotModelLiner(double a, double b, double yt, double ut, double prev_ut, double prev_yt, double c, double d)
{
    return a * yt - b * pow(prev_yt, 2) + c * ut + d * sin(prev_ut);

}
double ModelLiner(double a, double b, double yt, double ut)
{
    return a * yt + b * ut;

}
void EnterValue(double &value, std::string nameValue)
{
    std::cout << nameValue;
    std::cin >> value;
}
void OutputModel(double y, double u, double NumLin, double NotNumLin, double aLiner, double bLiner, double PrevUt, double PrevYt, double aNotLiner, double bNotLiner, double c, double d)
{
    double Yt = y, Ut = u;
    std::cout << std::endl <<std::endl<< "Liner model";
    std::cout << "\t\t\tIteration number:" << "\t\t\t" << "Yt";
    for (int i = 0; i < NumLin; i++) {
        std::cout << std::endl;
        EnterValue(Ut, "enter value Ut:");

        Yt = ModelLiner(aLiner, bLiner, Yt, Ut);
        std::cout << "\t\t\t\t" << i + 1 << "\t\t\t\t"<<Yt;
    }


    std::cout << std::endl << std::endl<<"Not liner model";
    std::cout << "\t\t\tIteration number:" << "\t\t\t" << "Yt";
    for (int i = 0; i < NotNumLin; i++) {
        if (i > 0) {
            PrevUt = Ut, PrevUt = Yt;
            std::cout << std::endl;
            EnterValue(Ut, "enter value Ut:");
            Yt = NotModelLiner(aNotLiner, bNotLiner, Yt, Ut, PrevUt, PrevYt, c, d);
            std::cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
        }
        else {
            PrevUt = 0; PrevYt = 0;
            std::cout << std::endl;
            EnterValue(Ut, "enter value Ut:");
            Yt = NotModelLiner(aNotLiner, bNotLiner, Yt, Ut, PrevUt, PrevYt, c, d);
            std::cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
        }
    }

}

int main()
{
    double y=0, u=0, bLiner=0,aLiner=0,bNotLiner=0,aNotLiner=0, c=0, d=0, NumLin=0,NumNotLin=0, PrevUt=0, PrevYt=0;

    std::cout << "Number of iteration"<<std::endl;
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

    OutputModel(y, u, NumLin, NumNotLin, aLiner, bLiner, PrevUt, PrevYt, aNotLiner, bNotLiner, c, d);
}
