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

class temperature_Model {
        double temperature;
        double warm;
        int time;
    public:
        temperature_Model(double temp, double w, int t) {
            this->temperature = temp;
            this->warm = w;
            this->time = t;
        }
        string toString() const {
            return "{ y(t): " + to_string(this->temperature) + "; t: " + to_string(this->time) + " }";
        }
};

void showData(vector<temperature_Model>& temperatureModels) {
    for (const auto& model : temperatureModels) {
        cout << model.toString() << endl;
    }
}

vector<temperature_Model> linear_Model(int time, double temperature) {
    vector<temperature_Model> linear_temperatures;

    for (int t = 1; t <= time; t++) {
        double cur_Warm = WARM;
        
        temperature = round((A * temperature + B * cur_Warm) * 100) / 100;
        linear_temperatures.push_back(temperature_Model(temperature, cur_Warm, t));
    }

    return linear_temperatures;
}

vector<temperature_Model> non_Linear_Model(int time, double temperature) {
    vector<temperature_Model> non_Linear_temperatures;

    double prev_temperature = 0;
    double prev_Warm = 0;

    for (int t = 1; t <= time; t++) {
        double cur_Warm = WARM;

        temperature = A * temperature - B * pow(prev_temperature, 2) + C * cur_Warm + D * sin(prev_Warm);
        temperature = round(temperature * 100) / 100;

        non_Linear_temperatures.push_back(temperature_Model(temperature, cur_Warm, t));

        prev_temperature = temperature;
        prev_Warm = cur_Warm;
    }

    return non_Linear_temperatures;
}

int main()
{
    int time;
    cout << "Input time param: ";
    cin >> time;

    int temperature;
    cout << "Input initial temperature: ";
    cin >> temperature;

    cout << "Linear model data output" << endl;
    auto linear = linear_Model(time, temperature);
    showData(linear);

    cout << "Non linear model data output" << endl;
    auto nonLinear = non_Linear_Model(time, temperature);
    showData(nonLinear);

    return 0;
}