#include <iostream>
#include <cmath>
using namespace std;
class Model {
public:
    virtual ~Model() = default;
       virtual double simulateT(double Yt, double Uw) = 0;
};
//линейная модель
class Linear : public Model {
private:
    double fg;
    double hhj;

public:
    Linear(double a, double b) : fg(a), hhj(b) {}

 
        virtual ~Linear() = default;

    double simulateT(double Yt, double Uw) override {
        return fg * Yt + hhj * Uw;
    }
};
//Нелинейная модель
class Nonlinear : public Model {
private:
     double k;
       double sd;
         double c;
           double d;
             double PreYt = 0;
    double PreUw = 0;

public:
    Nonlinear(double a, double b, double c, double d) : k(a), sd(b), c(c), d(d) {}

   
        virtual ~Nonlinear() = default;

    double simulateT(double Yt, double Uw) override {
        double calc = k * Yt - sd * pow(PreYt, 2) + c * Uw + d * sin(PreUw);
        PreYt = Yt;
        PreUw = Uw;
        return calc;
    }
};

void modeling(Model& model, double Yt, int numOfTimeModeling) {
    double Uw;
    for (int moment = 1; moment <= numOfTimeModeling; ++moment) {
        cout << "Input Uw-parameter: ";
        cin >> Uw;
        Yt = model.simulateT(Yt, Uw);
        cout << "\t\t\t" << moment << "\t\t" << Yt << endl;
    }
}

int main() {
        double Yt;
          double a;
         double b;
           double c;
              double d;
                 double numOfTimeModeling;

   
        cout << "-input Linear's coefs-" << endl;
      cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Linear linear(a, b);

    cout << "-input Nonlinear's coefa-" << endl;
    cout << "a: ";
   cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
   cin >> c;
   cout << "d: ";
    cin >> d;
    Nonlinear nonlinear(a, b, c, d);

    cout << "-Yt-" << endl;
    cout << "Yt: ";
    cin >> Yt;

    cout << "-number of time-" << endl;
    cout << "Number of time: ";
    cin >> numOfTimeModeling;

   cout << "-Linear-" <<endl;
    modeling(linear, Yt, numOfTimeModeling);

    cout << "-Nonlinear-" <<endl;
    modeling(nonlinear, Yt, numOfTimeModeling);
}