#include <iostream>
#include <cmath>

using namespace std;
class Object {
public:
    virtual ~Object() = default;
    virtual double ModelFunction(double Yt, double Ut) = 0;
    virtual void OutputModel(double y, double u, int NumLin) = 0;
};
class NotModelLinerValue : public Object
{
public:
    double a;
    double b;
    double prev_ut = 0;
    double prev_yt = 0;
    double c;
    double d;
    NotModelLinerValue(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
    ~NotModelLinerValue() override = default;
    double ModelFunction(double yt, double ut) override {
        return a * yt - b * pow(prev_yt, 2) + c * ut + d * sin(prev_ut);
    }
    void OutputModel(double y, double u, int NotNumLin) override
    {
        double Yt = y;
        double Ut = u;

        cout << endl << endl << "Not liner model";
        cout << "\t\t\tIteration number:" << "\t\t\t" << "Yt";
        for (int i = 0; i < NotNumLin; i++) {
            if (i > 0) {
                prev_ut = Ut;
                prev_yt = Yt;
                cout << endl << "enter value Ut:";
                cin >> Ut;
                Yt = this->ModelFunction(Yt, Ut);
                cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
            }
            else {
                prev_ut = 0; prev_yt = 0;
                cout << endl << "enter value Ut:";
                cin >> Ut;

                Yt = this->ModelFunction(Yt, Ut);
                cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
            }
        }

    }
};

class ModelLinerValue : public Object
{
public:
    double a;
    double b;
    ModelLinerValue(double a, double b) : a(a), b(b) {}
    ~ModelLinerValue() override = default;
    double ModelFunction(double yt, double ut) override {
        return a * yt + b * ut;
    }
    void OutputModel(double y, double u, int NumLin) override
    {
        double Yt = y;
        double Ut = u;
        cout << endl << endl << "Liner model";
        cout << "\t\t\tIteration number:" << "\t\t\t" << "Yt";
        for (int i = 0; i < NumLin; i++) {
            cout << endl << "enter value Ut:";
            cin >> Ut;

            Yt = this->ModelFunction(Yt, Ut);
            cout << "\t\t\t\t" << i + 1 << "\t\t\t\t" << Yt;
        }
    }
};

class Regulator
{
private:

    const double _td = 40;
    const double _t0 = 10;
    const double _k = 0.1;
    const double _t = 10;
    const double timeModeling = 30;
    double _uk = 0;

    double CurrentValueUk(double eK, double eK1, double eK2)
    {
        double _q0 = _k * (1 + _td / _t0);
        double _q1 = -_k * (1 + 2 * _td );
        double _q2 = _k * _td / _t0;
        _uk += _q0 * eK + _q1 * eK1 + _q2 * eK2;
        return _uk;
    }

public:
    void Regulating(double w, double y0, Object& obj)
    {
        double E1 = 0;
        double E2 = 0;
        double Y = y0;
        for (int i = 1; i <= timeModeling; i++) {
            double E;
            E = w - Y;
            _uk = CurrentValueUk(E, E1, E2);
            Y = obj.ModelFunction(y0, _uk);
            cout << "E = " << E << ", Yt = " << Y << ", Uk = " << _uk << endl;
            E2 = E1;
            E1 = E;
        }
        _uk = 0;
    }
};
template<typename T> T EnterValue(string const& enter, T value)
{
    cout << enter;
    cin >> value;
    return value;
}
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
    const double W = 8;
    const double y0 = 3;
    cout << "Number of iteration" << endl;
    EnterValue("Liner Model:", NumLin);
    EnterValue("Not Liner Model:", NumNotLin);

    EnterValue("enter value Y:", y);
    EnterValue("enter value U:", u);


    cout << endl << "Liner model" << endl;
    EnterValue("enter value A:", aLiner);
    EnterValue("enter value B:", bLiner);

    cout << endl << "Not liner model" << endl;
    EnterValue("enter value A:", aNotLiner);
    EnterValue("enter value B:", bNotLiner);
    EnterValue("enter value C:", c);
    EnterValue("enter value D:", d);
    ModelLinerValue modelLin(aLiner, bLiner);
    modelLin.OutputModel(y, u, NumLin);
    NotModelLinerValue notmodelLin(aNotLiner, bNotLiner, c, d);
    notmodelLin.OutputModel(y, u, NumLin);

    Regulator PIDregulator;


    cout << "Liner Model:"<<endl;
    PIDregulator.Regulating(W, y0, modelLin);
    cout << endl;

    cout << "Not linear model" << endl;
    PIDregulator.Regulating(W, y0, notmodelLin);
    return 0;

}