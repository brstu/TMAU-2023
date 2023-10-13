#include <iostream>
#include <cmath>

using namespace std;

#define newmodu 16		



          double nLin(double y[newmodu], double u, double a, double b, double c, double d) {
          double ng[newmodu];
          y[1] = b * u + a * y[0];
          	ng[1] = y[1];
				for (int i = 2; i < newmodu; i++) {
				y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + d * sin(u) + c * u;
				ng[i] = y[i];
				}
				return ng[newmodu - 1];
}

		double Lin(double y[newmodu], double u, double a, double b) {
			double ng[newmodu];
				for (int i = 1; i < newmodu; i++) {
					y[i] = b * u + a * y[i - 1];
					ng[i] = y[i];
					}
					return ng[newmodu - 1];
					}


int main() {

double temperat[newmodu];
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
          for (int i = 0; i < newmodu; i++) {
                    cout << "y[" << i << "]=" << temperat[i] << endl;
          }
          }
                    else {
          nLin(temperat, chowa, z, x, c, v);
                    for (int i = 0; i < newmodu; i++) {
                              cout << "y[" << i << "]=" << temperat[i] << endl;
          }
                              }

system("pause");
return 0;
}