#include <iostream>
#include <cmath>

double linearModel(double inputTemperature_Yt, double inputWarm_U, double a, double b) //Вычисление линейной функции
{
	return (a * inputTemperature_Yt)+(b* inputWarm_U);
}

double nonLinearModel(double inputTemperature_Yt, double inputTemperature_Yt_1, double inputWarm_U, double a, double b, double c, double d)  //Вычисление нелинейной функции
{
	return (a * inputTemperature_Yt) - b*pow(inputTemperature_Yt_1,2)+(c*inputWarm_U)+d*sin(inputWarm_U);
}

int main() 
{
	const double linearA = 1.6; //создание переменных для вычисления функций
	const double linearB = 0.9;
	const double nonLinearA = 0.8;
	const double nonLinearB = 0.6;
	const double nonLinearC = 0.5;
	const double nonLinearD = 0.3;

	double linearY = 0.0;
	double nonLinearY = 0.0;
	double previousNonLinearY = 0.0;

	double inputU = 0;

	int timeT;

	std::cout << "enter Warm: ";
	std::cin >> inputU;
	std::cout << "enter Time: ";
	std::cin >> timeT;
	std::cout << std::endl;

	for (int i = 1; i <= timeT; i++) //Цикл для моделирования временных шагов
	{
		linearY = linearModel(linearY, inputU, linearA, linearB);
		nonLinearY = nonLinearModel(nonLinearY, previousNonLinearY, inputU, nonLinearA, nonLinearB, nonLinearC, nonLinearD);
		previousNonLinearY = nonLinearY;	
		

		
		std::cout << "TIME: " << i << std::endl;
		std::cout << "LINEAR MODEL: " << linearY << std::endl;
		std::cout << "NONLINEAR MODEL: " << nonLinearY << std::endl<<std::endl;
		
	}


}