#include <iostream>
#include <vector>
#include <math.h>

const double sy1 = 20.0;
const double sy2 = 20.5;

class Synchronizable
{
protected:
    virtual ~Synchronizable() = default;
public:
    /**
     * \brief   Required function to initialize the simulation process.
     *
     * \details The function places several values of a sequence to calculate
     *          a first approximation. The number of values is determined by
     *			the mathematical model, and is fixed in the implementation of
     *			a particular class, and is also taken into account when calling
     *			a method.
     *
     * \param[in]     arrStart		Array of the first numbers of the sequence.
     *								The size is determined for each specific
     *								class.
     */
    virtual void sync(std::vector <double>& arrStart) = 0;
};

class Model : protected Synchronizable
{
    /** /file Model.h
     *  /brief Temperature simulation module.
     *
     *  Сontains a representation of the
     *	temperature control class.
     *
     *  /author Mikhail Liashenko
     *  /bug No bugs.
     */
private:

    double u;	///< Parameter u
    double u_p;	///< Parameter u_p
    double y;	///< Parameter y
    double y_p;	///< Parameter y_p
    double a;	///< Parameter a
    double b;	///< Parameter b
    double c;	///< Parameter c
    double d;	///< Parameter d

public:
    explicit Model(std::vector <double>& con, double strt1, double strt2) {
        init(con, strt1, strt2);
    };

    void init(std::vector <double>& con, double strt1, double strt2);

    ///Should recive 3 starting parameters
    void sync(std::vector <double>& arrStart) override;

    /**
     * \brief   Computate next state calculation operation linear
     *			system
     *
     * \param[in]	u_n		The following value of the measure of
     *						external influence on the system.
     *
     * \return		next state calculation operation linear system
     */
    double stepModelingNL(double u_n);

    /**
     * \brief   Computate next state calculation operation
     *			non-linear system
     *
     * \param[in]	u_n		The following value of the measure of
     *						external influence on the system.
     *
     * \return		next state calculation operation non-linear
     *				system
     */
    double stepModelingL(double u_n);
};

class Regulator : protected Synchronizable
{
    /** /file Regulator.h
     *  /brief Standart PID Regulator.
     *
     *  Contains the implementation of a PID
     *  controller, methods for its creation,
     *  configuration, and use.
     *
     *  /author Mikhail Liashenko
     *  /bug No bugs.
     */

private:
    double ek;		///< Parameter ek
    double ek_p;	///< Parameter ek_p
    double ek_pp;	///< Parameter ek_pp
    double u_p;		///< Parameter u_p
    double K;		///< Parameter K
    double T;		///< Parameter T
    double Td;		///< Parameter Td
    double T0;		///< Parameter T0
    double q0;		///< Parameter q0
    double q1;		///< Parameter q1
    double q2;		///< Parameter q2

public:
    /**
     * \brief   Class constructor.
     *
     * \note    After initializing the class object, required
     *			to complete the synchronization procedure.
     *
     * \param[in]	con		Array of simulation constants.
     * \param[in]	start	Initial approximation
     */
    explicit Regulator(std::vector <double>& con, double start) {
        init(con, start);
    };

    void init(std::vector <double>& con, double start);

    /**
     * \brief   Computate and define simulation constants by setting
     *			parameters.
     */
    void defConstants();

    ///Should recive 3 starting parameters
    void sync(std::vector <double>& arrStart) override;

    /**
     * \brief   Computate and define modelling variation by
     *			simulation constants.
     */
    double deltaU() const;

    /**
     * \brief   Iterative operation of computation the next
     *			model parameter.
     *
     * \param[in]	ek_n	Next model state.
     * \return		This function returns the calculated
     *				model parameter.
     */
    double step(double ek_n);
};

int main()
{
    int num = 30;
    std::vector <double> u;
    //Генератор ПСЧ
    std::cout << "Natural temperature" << std::endl;
    for (int i = 0; i < num; i++) {
        u.push_back(20.0 - i / 5.0 + i * i / 9.0 - i * i * i / 260.0);
        std::cout << u[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "Nonlineal model" << std::endl;
    std::vector <double> arr_m1 = { 1, 0.01, 0.5, 0.7 };
    Model model1(arr_m1, sy1, sy2);
    std::vector <double> arr_aux1 = { u[0], u[1] };
    model1.sync(arr_aux1);//////////////////////////////////////////////////
    std::vector <double> vecMod1;
    vecMod1.push_back(sy1); std::cout << vecMod1.back() << "\t";
    vecMod1.push_back(sy2); std::cout << vecMod1.back() << "\t";
    for (int i = 2; i < u.size(); i++) {
        vecMod1.push_back(model1.stepModelingNL(u[i]));
        std::cout << vecMod1.back() << "\t";
    }
    std::cout << std::endl;

    std::cout << "Nonlineal model control" << std::endl;
    std::vector <double> arr1 = { 0.1, 0.09, 0.007, 0.001 };
    Regulator reg1(arr1, 20);
    std::vector <double> arr_aux2 = { 0, 0, 0 };
    reg1.sync(arr_aux2);
    std::vector <double> vecReg1;
    for (int i = 0; i < u.size(); i++) {
        vecReg1.push_back(reg1.step(vecMod1[i]));
        std::cout << vecReg1[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "Lineal model" << std::endl;
    std::vector <double> arr_m2 = { 1.15, 0.007, 0, 0 };
    Model model2(arr_m2, sy1, sy2);
    model1.sync(arr_aux1);
    std::vector <double> vecMod2;
    vecMod2.push_back(sy1); std::cout << vecMod2.back() << "\t";
    for (int i = 1; i < u.size(); i++) {
        vecMod2.push_back(model2.stepModelingNL(u[i]));
        std::cout << vecMod2.back() << "\t";
    }
    std::cout << std::endl;

    std::cout << "Lineal model control" << std::endl;
    std::vector <double> arr2 = { 0.6, 0.8, 0.1, 0.01 };
    Regulator reg2(arr2, 20);
    std::vector <double>  arr_aux3 = { 15, 19, 18 };
    reg2.sync(arr_aux3);
    std::vector <double> vecReg2;
    for (int i = 0; i < u.size(); i++) {
        vecReg2.push_back(reg2.step(vecMod2[i]));
        std::cout << vecReg2[i] << "\t";
    }

}

    void Model::init(std::vector <double>& con, double strt1, double strt2) {
    this->a = con[0];
    this->b = con[1];
    this->c = con[2];
    this->d = con[3];
    this->y = strt1;
    this->y_p = strt2;
    this->u = 0;
    this->u_p = 0;
};

    void Model::sync(std::vector <double>& arrStart) {
        this->u = arrStart[0];
        this->u_p = arrStart[1];
    };

    double Model::stepModelingNL(double u_n) {
        u_p = u;
        u = u_n;
        double y_n = (a * y - b * pow(y_p, 2) + c * u + d * sin(u_p));
        y_p = y;
        y = y_n;
        return y;
    };

    double Model::stepModelingL(double u_n) {
        u = u_n;
        double y_n = a * y - b * u;
        return y_n;
    };

    void Regulator::init(std::vector <double>& con, double start) {
        this->K = con[0];
        this->T = con[1];
        this->Td = con[2];
        this->T0 = con[3];
        this->u_p = start;
        defConstants();
        this->ek = 0;
        this->ek_p = 0;
        this->ek_pp = 0;
        this->u_p = 0;
    };

    void Regulator::defConstants() {
        this->q0 = K * (1 + Td / T0);
        this->q1 = -K * (1 + 2 * Td / T0 - T0 / T);
        this->q2 = K * Td / T0;
    };

    void Regulator::sync(std::vector <double>& arrStart) {
        this->ek = arrStart[0];
        this->ek_p = arrStart[1];
        this->ek_pp = arrStart[2];
    };

    double Regulator::deltaU() const {
        return(q0 * ek + q1 * ek_p + q2 * ek_pp);
    };

    double Regulator::step(double ek_n) {
        ek_pp = ek_p;
        ek_p = ek;
        ek = ek_n;
        double u = u_p + deltaU();
        u_p = u;
        return u;
    };