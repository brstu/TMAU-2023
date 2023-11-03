#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class LinearModel
{
private:
    double A;
    double B;
    double currentTemp;

public:

    LinearModel(double A, double B, double temp)
        : A(A), B(B), currentTemp(temp)
    {
    }

    double equation(double temp, double warm)
    {
        currentTemp = A * temp + B * warm;
        return currentTemp;
    }

};

class NonLinearModel
{
private:
    double A;
    double B;
    double C;
    double D;
    double prevTemp = 0;
    double currentTemp;
    double warm = 0;
public:

    NonLinearModel(double A, double B, double C, double D, double temp)
        : A(A), B(B), C(C), D(D), currentTemp(temp)
    {
    }

    double equation(double temp, double warm1)
    {
        currentTemp = A * temp - B * pow(prevTemp, 2) + C * warm1 + D * sin(this->warm);
        this->warm = warm1;
        prevTemp = temp;
        return currentTemp;
    }
};


class Regulator
{
private:
    double T;
    double TP;
    double TM;
    double K;
    double u;

public:

    Regulator(double T, double TP, double TM, double K)
        : T(T), TP(TP), TM(TM), K(K)
    {
    }

    double temperature(double e, double em1, double em2) {
        double q0;
        double q1;
        double q2;

        q0 = K * (1 + TM / TP);
        q1 = -K * (1 + 2 * TM / TP - TP / T);
        q2 = K * TM / TP;
        u += q0 * e + q1 * em1 + q2 * em2;
        return u;
    }
};

void PID(double w, double y0, Regulator& reg, LinearModel& md1, NonLinearModel& md2, bool mode) {
    ofstream fout;
    fout.open("D:\\result.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        double em1 = 0;
        double em2 = 0;
        double y = y0;
        for (int i = 0; i < 100; i++) {
            double e;
            double u;
            e = w - y;
            u = reg.temperature(e, em1, em2);

            if (mode == true) {
                y = md1.equation(y0, u);
            }
            else
            {
                y = md2.equation(y0, u);
            }

            fout << "E=" << e << " Y=" << y << " U=" << u << endl;
            em2 = em1;
            em1 = e;
        }
    }
    fout.close();
}

int main() {
    setlocale(0, "");
    ofstream fout;
    fout.open("D:\\result.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        fout << "LinearModel:" << endl;
        LinearModel l(0.333f, 0.667f, 1);
        NonLinearModel nl(1.0f, 0.0033f, 0.525f, 0.525f, 1.0f);
        Regulator regl(10, 10, 50, 0.1f);
        PID(5, 2, regl, l, nl, true);
        fout << "NonLinearModel:" << endl;
        Regulator regnl(10, 10, 50, 0.1f);
        PID(5, 2, regnl, l, nl, false);
    }
    cout << "Сохранено в result.txt" << endl;
    return 0;
}