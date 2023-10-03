#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double aN ; double bN ; double cN ; double dN;

double LineModel(double Yt, double a, double b, double Ut) {
    return a * Yt + b * Ut;
}

double NLineModel(double Yt, double PreviousYt, double Ut, double PreviousUt) {
    return aN * Yt - bN * PreviousYt * PreviousYt + cN * Ut + dN * sin(PreviousUt);
}

int main() {
    setlocale(LC_ALL, "Russian");
    double y0; double u0; double aL; double bL; double Yt; double PreviousYt; double Ut; double PreviousUt;
    int LinIter; int NLinIter;

    cout << "Введите значение  y: ";
    cin >> y0;
    cout << "Введите значение u: ";
    cin >> u0;

    cout << endl << "Параметры линейной" << endl;
    cout << "Введите значение a: ";
    cin >> aL;
    cout << "Введите значение b: ";
    cin >> bL;

    cout << endl << "Параметры нелинейной модели" << endl;
    cout << "Введите значение a: ";
    cin >> aN;
    cout << "Введите значение b: ";
    cin >> bN;
    cout << "Введите значение c: ";
    cin >> cN;
    cout << "Введите значение d: ";
    cin >> dN;

    cout << endl << "Количество итераций" << endl;
    cout << "Линейной модели: ";
    cin >> LinIter;
    cout << "Нелинейной модели: ";
    cin >> NLinIter;

    cout << endl << endl << "Линейная модель";
    Yt = y0; Ut = u0;
    cout << "\t\t\tИтерация" << "\t\t\t" << "Yt";

    for (int iterator = 0; iterator < LinIter; iterator++) {
        cout << endl << "Введите Ut: ";
        cin >> Ut;

        Yt = LineModel(Yt, aL, bL, Ut);
        cout << "\t\t\t" << iterator + 1 << "\t\t\t" << Yt;
    }
    cout << "" << endl << endl << "Нелинейная модель";
    Yt = y0; Ut = u0;
    cout << "\t\tИтерация" << "\t\t\t" << "Yt";

    for (int iterator = 0; iterator < LinIter; iterator++) {
        if (iterator > 0) {

            PreviousUt = Ut; PreviousYt = Yt;
            cout << endl << "Введите Ut: ";
            cin >> Ut;

            Yt = NLineModel(Yt, PreviousYt, Ut, PreviousUt);
            cout << "\t\t\t" << iterator + 1 << "\t\t\t" << Yt;
        }
        else {

            PreviousUt = 0; PreviousYt = 0;
            cout << endl << "Введите Ut: ";
            cin >> Ut;

            Yt = NLineModel(Yt, PreviousYt, Ut, PreviousUt);
            cout << "\t\t\t" << iterator + 1 << "\t\t\t" << Yt;
        }
    }
}

