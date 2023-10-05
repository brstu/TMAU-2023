#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const double A = 0.5;
const double B = 1;
const double C = 1.2;
const double D = 0.4;
const double WARM = 1;



class ModelTemp {
public:
    double temp;
    double warm;
    int t;

    ModelTemp(double temp, double warm, int t) : temp(temp), warm(warm), t(t) {
    }

    string toString() const {
        return "{ y(t): " + to_string(this->temp) + "; t: " + to_string(this->t) + " }";
    }

};

void showData(const vector<ModelTemp>& tempModels)) {
    for (const auto& model : tempModels) {
        cout << model.toString() << endl;
    }
}

vector<ModelTemp> LinearModel(int time, double temp) {
    vector<ModelTemp> linearTemps;

    for (int t = 1; t <= time; t++) {
        double currentWarm = WARM;
        temp = round((A * temp + B * currentWarm) * 100) / 100;
        linearTemps.emplace_back(temp, currentWarm, t);
    }

    return linearTemps;
}

vector<ModelTemp> NonLinearModel(int time, double temp) {
    vector<ModelTemp> nonLinearTemps;
    double PreviousTemp = 0;
    double PreviousWarm = 0;

    for (int t = 1; t <= time; t++) {
        double currentWarm = WARM;
        temp = A * temp - B * pow(PreviousTemp, 2) + C * currentWarm + D * sin(PreviousWarm);
        temp = round(temp * 100) / 100;
        nonLinearTemps.emplace_back(temp, currentWarm, t);
        PreviousTemp = temp;
        PreviousWarm = currentWarm;
    }

    return nonLinearTemps;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int temp;
    cout << "Введите начальную температуру: ";
    cin >> temp;
    int time;
    cout << "Введите время: ";
    cin >> time;


    cout << "Линейная модель" << endl;
    auto linear = LinearModel(time, temp);
    showData(linear);

    cout << "Нелинейная модель" << endl;
    auto nonLinear = NonLinearModel(time, temp);
    showData(nonLinear);

    return 0;
}
