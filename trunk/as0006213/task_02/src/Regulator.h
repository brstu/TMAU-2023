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
#pragma once
#include "Synchronizable.h"

class Regulator : public Synchronizable
{
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
	double q2;		///< Parameter q2÷

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
	explicit Regulator(double* con, double start) {
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

	/**
	 * \brief   Computate and define simulation constants by setting
	 *			parameters.
	 */
	void defConstants();

	///Should recive 3 starting parameters
	void sync(double* arrStart) override; 

	/**
	 * \brief   Computate and define modelling variation by 
	 *			simulation constants.
	 */
	double deltaU();

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

