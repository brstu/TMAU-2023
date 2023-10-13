#include <iostream>
#include <cmath>

using namespace std;





          double nLin(double y[16], double u, double a, double b, double c, double d) {
          double ng[16];
          y[1] = b * u + a * y[0];
          	ng[1] = y[1];
				for (int i = 2; i < 16; i++) {
				y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + d * sin(u) + c * u;
				ng[i] = y[i];
				}
				return ng[15];
}

		double Lin(double y[16], double u, double a, double b) {
			double ng[16];
				for (int i = 1; i < 16; i++) {
					y[i] = b * u + a * y[i - 1];
					ng[i] = y[i];
					}
					return ng[15];
					}


int main() {

double temperat[16];
	double chowa;
		int temp;

           cout << "choose : \n 0 - Lin \n 1,2,3,4,5,6,7,8,9 - nLin" << endl;
           cin >> temp;
           cout << "enter temperat " << endl;
           cin >> temperat[0];
           cout << "enter chowa " << endl;
		   cin >> chowa;


         double z = 0.1;
         double x = 0.01;
         double c = 0.03;
         double v = 0.02;
          if (temp == 0) {
          Lin(temperat, chowa, z, x);
          for (int i = 0; i < 16; i++) {
                    cout << "y[" << i << "]=" << temperat[i] << endl;
          }
          }
                    else {
          nLin(temperat, chowa, z, x, c, v);
                    for (int i = 0; i < 16; i++) {
                              cout << "y[" << i << "]=" << temperat[i] << endl;
          }
                              }

system("pause");
return 0;
}