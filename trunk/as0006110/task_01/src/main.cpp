#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

	const double A = 0.5;
	const double B = 1;
	const double C = 1.2;
	const double D = 0.4;
	const double teplo = 1;

	class Temp_mod {
		public:
			double gradus;
			double teplo;
			int vrem9;
			Temp_mod(double temp, double teplo, int t) : gradus(temp), teplo(teplo), vrem9(t) {
			}
			string toString() const {
			return "{ y(t): " + to_string(this->gradus) + "; t: " + to_string(this->vrem9) + " }";
	}	
	};

	void SD(const vector<Temp_mod>& GM) {
	for (const auto& model : GM) {
	cout << model.toString() << endl;
	}
	}

			vector<Temp_mod> L_M(int vrem9, double gradus) {
			vector<Temp_mod> linear_graduss;

	for (int t = 1; t <= vrem9; t++) {
	double cur_teplo = teplo;
	gradus = round((A * gradus + B * cur_teplo) * 100) / 100;
	linear_graduss.emplace_back(gradus, cur_teplo, t);
	}

	return linear_graduss;
	}

			vector<Temp_mod> non_L_M(int vrem9, double gradus) {
			vector<Temp_mod> non_Linear_graduss;

			double prev_gradus = 0;
			double prev_teplo = 0;

			for (int t = 1; t <= vrem9; t++) {
			double cur_teplo = teplo;

			gradus = A * gradus - B * pow(prev_gradus, 2) + C * cur_teplo + D * sin(prev_teplo);
			gradus = round(gradus * 100) / 100;

			non_Linear_graduss.emplace_back(gradus, cur_teplo, t);

			prev_gradus = gradus;
			prev_teplo = cur_teplo;
			}

			return non_Linear_graduss;
			}

		int main()
		{
		int vrem9;
		cout << "Input vrem9 param: ";
		cin >> vrem9;

		int gradus;
		cout << "Input initial gradus: ";
		cin >> gradus;

		cout << "Linear model data output" << endl;
		auto linear = L_M(vrem9, gradus);
		SD(linear);

		cout << "Non linear model data output" << endl;
		auto nonLinear = non_L_M(vrem9, gradus);
		SD(nonLinear);

		return 0;
		}