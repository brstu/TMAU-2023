#include <iostream>
#include <cmath>
#include <fstream>
/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Дубновцкая М.С. АС-61
*/


class AbstrModel
{
public:
    virtual ~AbstrModel() = default;
    virtual double calculModel(double yCurr, double vvedWarm) = 0;
};

class LinModel : public AbstrModel
{
private:
    double a_;     
    double b_;     
    double ySl_; 
public:
    LinModel(double a, double b, double ySl) :
        a_(a),
        b_(b),
        ySl_(ySl)
    { }

   
    double calculModel(double yCurr, double vvedWarm) override
    {
        ySl_ = a_ * yCurr + b_ * vvedWarm;
        return ySl_;
    }
};

class NonLinModel : public AbstrModel
{
private:
    double a_;         
    double b_;         
    double c_;         
    double d_;         
    double yPred_ = 0; 
    double ySl_;     
    double wPred_ = 0; 

public:
    NonLinModel(double a, double b, double c, double d, double ySl) :
        a_(a),
        b_(b),
        c_(c),
        d_(d),
        ySl_(ySl)
    { }

    double calculModel(double yCurr, double vvedWarm) override
    {
        ySl_ = a_ * yCurr - b_ * pow(yPred_, 2) + c_ * vvedWarm + d_ * sin(wPred_);
        yPred_ = yCurr;
        wPred_ = vvedWarm;
        return ySl_;
    }
};
class pid_REGULATOR
{
private:
    double t_;      
    double t0_;     
    double td_;     
    double k_;      
    double uk_ = 0; 

    double calcul_uk(double ek, double ek1, double ek2)
    {
        double q0 = k_ * (1 + td_ / t0_);
        double q1 = -k_ * (1 + 2 * td_ / t0_ - t0_ / t_); 
        double q2 = k_ * td_ / t0_; 
        uk_ += q0 * ek + q1 * ek1 + q2 * ek2;
        return uk_;
    }
public:
    pid_REGULATOR(double T, double T0, double TD, double K) :
        t_(T),
        t0_(T0),
        td_(TD),
        k_(K)
    { }

    void PIDpid_REGULATORCalculateAndWrite(double need, double start)
    {
        std::ofstream fout("results.txt");

        if (fout)
        {
            double ek;
            double ek1 = 0;
            double ek2 = 0;
            double y = start;
            double u;

            LinModel linear(0.333, 0.667, 1);
            fout << "Линейная модель: " << std::endl;
            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;
                u = calcul_uk(ek, ek1, ek2);
                y = linear.calculModel(start, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }

            ek1 = 0;
            ek2 = 0;
            y = start;
            uk_ = 0;

            fout << "Нелинейная модель: " << std::endl;
            NonLinModel nonLinear(1, 0.0033, 0.525, 0.525, 1);
            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;
                u = calcul_uk(ek, ek1, ek2);
                y = nonLinear.calculModel(start, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }
        }
        else
        {
            std::cout << "Не удалось открыть файл для того, чтобы записать результаты." << std::endl;
        }
    }
};

int main()
{
    setlocale(0, "");
    pid_REGULATOR object(10, 10, 40, 0.1);
    object.PIDpid_REGULATORCalculateAndWrite(5, 2);
    std::cout << "Данные сохранены в файле results.txt" << std::endl;
    return 0;
}