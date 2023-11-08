#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//add calculation constants
const double const_a = 1.34; const double const_b = 5.23; const double const_c = 4.37; const  double const_d = 3.95;
//add a function to obtain a linear model
double LineModel(double Yt, double a, double b, double Ut)
{
    return a * Yt + b * Ut;
}
//add a function to obtain a nonlinear model
double NotLineModel(double Yt, double PrevioustYt, double Ut, double PrevioustUt)
{
    return const_a * Yt - const_b * pow(PrevioustYt, 2) + const_c * Ut + const_d * sin(PrevioustUt);
}
//program starting point
int main()
{//setlocale(LC_ALL, "Russian");////allow the use of Russian language//upd: Initially I wanted to make the interface Russian-language, but I am confused that Gitkraken does not recognize Russian letters, and therefore all comments and results of the program were translated into English and presented in the report in the appropriate form
    double Yt; double PreviousYt; double Ut; double PreviousUt; double y0; double u0; double aL; double bL; //выделим память для расчетных переменных
    int LineIter; int NotLineIter;//выделим еще памяти для переменных - счетчиков
    //get the input values ??a and b
    cout << "Linear Model Parameters" << endl;
    cout << "Enter a:\t";
    cin >> aL;
    cout << "Enter b:\t";
    cin >> bL;
    //we get the input values ??y0 and u0
    cout << "Enter y:\t";
    cin >> y0;
    cout << "Enter u:\t";
    cin >> u0;
    //we get the number of tests of linear and nonlinear models
    cout << endl;
    cout << "Number of tests" << endl;
    cout << "Linear model: ";
    cin >> LineIter;
    cout << "Nonlinear model: ";
    cin >> NotLineIter;
    //Having received all the necessary variables, we proceed to modeling the linear model
    cout << endl;
    cout << "Linear model";
    Yt = y0; Ut = u0;
    //a cycle demonstrating the results of linear model calculations
    for (int iterator = 0; iterator < LineIter; iterator++) {
        cout << endl;
        cout << "Enter Ut: ";
        cin >> Ut;
        Yt = LineModel(Yt, aL, bL, Ut);
        cout << "iteration: " << iterator + 1 << ";" << " Yt: " << Yt;
    }
    cout << endl;
    cout << endl;
    cout << "Nonlinear model";
    Yt = y0; Ut = u0;
    //a cycle demonstrating the results of calculating a nonlinear model
    for (int iterator = 0; iterator < NotLineIter; iterator++) {
        if (iterator > 0) {
            PreviousUt = Ut; PreviousYt = Yt;
            cout << endl;
            cout << "Enter Ut: ";
            cin >> Ut;
            Yt = NotLineModel(Yt, PreviousYt, Ut, PreviousUt);
            cout << "iteration: " << iterator + 1 << ";" << " Yt: " << Yt;
        }
        else {
            PreviousUt = 0; PreviousYt = 0;
            cout << endl;
            cout << "Enter Ut: ";
            cin >> Ut;
            Yt = NotLineModel(Yt, PreviousYt, Ut, PreviousUt);
            cout << "iteration: " << iterator + 1 << ";" << " Yt: " << Yt;
        }
        cout << endl;
    }
}