#include <iostream>
#include <cmath>

const double a = 1;
const double bLin = 1;
const double bNonlin = 0.00001;
const double c = bLin;
const double d = 0.1;
void calculateLinearModel(int time, double yCurrent, double inputWarm);
void calculateNonlinearModel(int time, double yCurrent, double inputWarm);
int main()
{
	setlocale(0, "");
	double yCurrent = 0.0;
	double inputWarm = 0.0;
	int time = 0;
	do
	{
		std::cout << "Введите время (положительное число): "; std::cin >> time;
	} while (time <= 0);
	std::cout << "Введите температуру помещения: "; std::cin >> yCurrent;
	std::cout << "Введите значение тепла, на которое будет меняться температура: "; std::cin >> inputWarm;
	std::cout << "Линейная модель: " << std::endl;
	calculateLinearModel(time, yCurrent, inputWarm);
	std::cout << "Нелинейная модель: " << std::endl;
	calculateNonlinearModel(time, yCurrent, inputWarm);
	return 0;
}
void calculateLinearModel(int time, double yCurrent,double inputWarm)
{
	double yNext;
	while (time--)
	{
		yNext = (a * yCurrent) + (bLin * inputWarm);
		std::cout << yNext << std::endl;
		yCurrent = yNext;
	}
}

void calculateNonlinearModel(int time, double yCurrent, double inputWarm)
{
	double yNext;
	double yPrev = 0.0;
	double inputWarmPrev = 0.0;
	while (time--)
	{
		yNext = (a * yCurrent) - (bNonlin * pow(yPrev, 2)) + (c * inputWarm) + (d * sin(inputWarmPrev));
		std::cout << yNext << std::endl;
		yPrev = yCurrent;
		yCurrent = yNext;
		inputWarmPrev = inputWarm;
	}
}