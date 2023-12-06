#include <iostream>
#include <cmath>


using namespace std;

class Model{
public:

    virtual double simulate_temperature(double Yt, double Uw) = 0;


    virtual ~Model() = default;
};



class NonlinearModel : public Model {
private:

    double PreYt = 0;

    double PreUw = 0;
    double a; 
    double b; 
    double c; 
    double d; 

public:


    double simulate_temperature(double Yt, double Uw) final {
        double calc = a*Yt - b*pow(PreYt, 2) + c*Uw + d*sin(PreUw);
        PreYt = Yt;
        PreUw = Uw;
        return calc;
    }

    NonlinearModel(double a, double b, double c, double d):
        a(a),
        b(b),
        c(c),
        d(d) {}


    ~NonlinearModel() override = default;
};


void input_parametrs(double& a, double& b, double& c, double& d, bool is_nonlinearModel) {

    if (is_nonlinearModel) {
        cout << "Введите параметр с: "; cin >> c;
        cout << "Введите параметр d: "; cin >> d;
    }
    cout << "Введите параметр а: "; cin >> a;
    cout << "Введите параметр d: "; cin >> b;
}


class PIDregulator
{
private:

    const double T0 = 50;

    const double numOfTimeModeling = 30;

    double Uk = 0;

    const double K = 0.1;

    const double T = 10;

    const double TD = 80;


    double calculate_Uk(double e, double e1, double e2)
    {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        double q2 = K * TD / T0;
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:


    void Regulate(double w, double y0, Model& model)
    {  
        double e2 = 0;
        double y = y0;
        double e1 = 0;

        for (int i = 1; i <= numOfTimeModeling; i++) {
            double e;
            e = w - y;
            Uk = calculate_Uk(e, e1, e2);
            y = model.simulate_temperature(y0, Uk);
            cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << std::endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

class LinearModel : public Model {
private:
    double a;
    double b;
public:

    LinearModel(double a, double b) : a(a), b(b) {}

    double simulate_temperature(double Yt, double Uw) final {
        return a * Yt + b * Uw;
    }


    ~LinearModel() override = default;
};


int main() {
    setlocale(LC_ALL, "Russian");
    const double w = 8;

    const double y0 = 3;

    double a;

    double b;

    double c;

    double d;


    cout << "---Пожалуйста введите параметры линейной модели---" << endl;
    input_parametrs(a,b,c,d,false);
    LinearModel linear_model{a,b};


    cout << "---Пожалуйста введите параметры нелинейной модели---" << endl;
    input_parametrs(a,b,c,d,true);
    NonlinearModel nonlinear_model{a,b,c,d};




    PIDregulator pid_regulator;



    cout << "\t---Нелинейная модель---" << endl;
    pid_regulator.Regulate(w, y0, nonlinear_model);



    cout << "\t---Линейная модель---" << endl;
    pid_regulator.Regulate(w, y0, linear_model);
    cout << endl;
    system("Pause");
    return 0;
}



    
