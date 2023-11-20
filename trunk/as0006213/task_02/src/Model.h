/** /file Regulator.h
 *  /brief Standart PID Regulator.
 *
 *  Ñontains a representation of the 
 *	temperature control class.
 *
 *  /author Mikhail Liashenko
 *  /bug No bugs.
 */
#pragma once
#include <math.h>
#include "Synchronizable.h"

class Model : Synchronizable
{
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
	explicit Model(double* con, double strt1, double strt2) {
		this->a = con[0];
		this->b = con[1];
		this->c = con[2];
		this->d = con[3];
		this->y = strt1;
		this->y_p = strt2;
		this->u = 0;
		this->u_p = 0;
	};

	///Should recive 3 starting parameters
	void sync(double* arrStart) override;

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