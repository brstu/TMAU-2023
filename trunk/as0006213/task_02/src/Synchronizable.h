#pragma once
class Synchronizable
{
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
	virtual void sync(double* arrStart) = 0;
};

