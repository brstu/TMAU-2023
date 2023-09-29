#include <iostream>
using namespace std;
int main()
{
    const double a = 1.1;
    const double b = 0.03;
    const double c = 0.7;
    const double d = 0.06;
    double Ytemp = 0;
    double Uwarm = 0;
    double Ytemp_1 = 17;
    double Uwarm_1 = 19;
    cout << "Input temperature: ";
    cin >> Ytemp;
    cout << "\nInput warm: ";
    cin >> Uwarm;
    cout << "\n";
    double y[15] = { 0 };
    y[0] = Ytemp_1;
    y[1] = Ytemp;
    for (int i = 2; i < 15; i++) {
        y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * Uwarm + d * sin(Uwarm_1);
    }
    cout << "For nonlinear model:\n";
    for (int i = 0; i < 15; i++) cout << "y["<< i <<"] = " << y[i] << " \n";
    cout << "\n";
    for (int i = 2; i < 15; i++) {
        y[i] = a * y[i - 1] + b * Uwarm;
    }
    cout << "For linear model:\n";
    for (int i = 0; i < 15; i++) cout << "y[" << i << "] = " << y[i] << " \n";
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
	 //Константы
    const double A_means_AncientApparation = 1.1;
    const double B_means_BountyHunter = 0.03;
    const double C_means_CentaurWarrunner = 0.7;
    const double D_means_DarkSeer = 0.06;
    double Ytemp = 0;
    double Uwarm = 0;
    double Ytemp_1 = 17;
    double Uwarm_1 = 19;
	 //ВВод данных
    cout << "Input temperature: ";
    cin >> Ytemp;
    cout << "Input warm: ";
    cin >> Uwarm;
	 double Temprature_means_TrollWarlord[15] = { 0 };
    Temprature_means_TrollWarlord[0] = Ytemp_1;
    Temprature_means_TrollWarlord[1] = Ytemp;
	 //Вычисления по формуле линейной модели
	 for (int index_of_copypast = 2; index_of_copypast < 15; index_of_copypast++) { Temprature_means_TrollWarlord[index_of_copypast] = A_means_AncientApparation * Temprature_means_TrollWarlord[index_of_copypast - 1] + B_means_BountyHunter * Uwarm; }
    cout << "For linear model:\n";
    for (int second_index = 0; second_index < 15; second_index++) cout << "Temperature at the " << second_index << " time: " << Temprature_means_TrollWarlord[second_index] << (Temprature_means_TrollWarlord[second_index]>20?". It is soo good)))":". It is soo hot(((") <<" \n";
	 cout << "\n";
	 //Вычисления по формуле нелинейной модели
    for (int third_index = 2; third_index < 15; third_index++) { Temprature_means_TrollWarlord[third_index] = A_means_AncientApparation * Temprature_means_TrollWarlord[third_index - 1] - B_means_BountyHunter * pow(Temprature_means_TrollWarlord[third_index - 2], 2) + C_means_CentaurWarrunner * Uwarm + D_means_DarkSeer * sin(Uwarm_1); }
    cout << "For nonlinear model:\n";
    for (int some_other_index = 0; some_other_index < 15; some_other_index++) cout << "Temperature at the "<< some_other_index <<" time: " << Temprature_means_TrollWarlord[some_other_index] << (Temprature_means_TrollWarlord[some_other_index]>20?". It is soo good)))":". It is soo hot(((") << " \n";
	 return 0;
}
