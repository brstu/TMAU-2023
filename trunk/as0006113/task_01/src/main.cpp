#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;




class temMod {
public:

    double temper;


    double war;


    int t;

    temMod(double temper, double war, int t) : temper(temper), war(war), t(t)  {
    }

     string toString() const {

            return "{ y(t): " + to_string(this->temper) + "; t: " + to_string(this->t) + " }";
    }


};


 const double A = 0.5;



 const double B = 1;


 const double C = 1.2;


 const double D = 0.4;


 const double WARM = 1;



void showData(const vector<temMod>& temperMods) {
    for (const auto& model : temperMods) {
        cout << model.toString() << endl;
    }
}







vector<temMod> simulateLinearMod(int time, double temper) {
    vector<temMod> lineartempers;

    for (int t = 1; t <= time; t++) {
    double curwar = WARM;
    temper = round((A * temper + B * curwar) * 100) / 100;
    lineartempers.emplace_back(temper, curwar, t);
    }

    

    return lineartempers;
}



vector<temMod> simulateNonLinearMod(int time, double temper) {
        vector<temMod> nonLineartempers;
        double prtemper = 0;
        double prwar = 0;



    for (int t = 1; t <= time; t++) {


    double curwar = WARM;


    temper = A * temper - B * pow(prtemper, 2) + C * curwar + D * sin(prwar);


    temper = round(temper * 100) / 100;


    nonLineartempers.emplace_back(temper, curwar, t);
    prtemper = temper;


    prwar = curwar;
    }



    return nonLineartempers;
}




int main()
{
    int time;
    cout << "Input time parameter: ";
    cin >> time;

    int temper;
    cout << "Input initial temperature: ";
    cin >> temper;

    cout << "Linear model data" << endl;
    auto linear = simulateLinearMod(time, temper);
    showData(linear);

    cout << "Non linear model data" << endl;
    auto nonLinear = simulateNonLinearMod(time, temper);
    showData(nonLinear);

    return 0;
}