#include <iostream>
#include <cmath>
#include <vector>

constexpr int N = 16;		// kolichestvo izmeneniy temperaturi;

float linear_transformation(std::vector<float>& y, float u, float a, float b) {
    std::vector<float> new_temperature(N);

    for (int i = 1; i < N; i++) {
        y[i] = a * y[i - 1] + b * u;
        new_temperature[i] = y[i];
    }
    return new_temperature[N-1];
}

float nonlinear_transformation(std::vector<float>& y, float u, float a, float b, float c, float d) {
    std::vector<float> new_temperature(N);
    y[1] = a * y[0] + b * u;
    new_temperature[1] = y[1];

    for (int i = 2; i < N; i++) {
        y[i] = a * y[i - 1] - b * pow(y[i - 2], 2) + c * u + d * sin(u);
        new_temperature[i] = y[i];
    }
    return new_temperature[N-1];
}

int choose_transformation() {

    std::vector<float> temperature(N);
    float warm;
    const float a = 0.1;
    const float b = 0.1;	
    const float c = 0.3;		
    const float d = 0.2;		
    int temp;

    std::cout << "choose type of transformation: \n 1 - linear \n 2 - nonlinear" << std::endl;
    std::cin >> temp;
    std::cout << "enter temperature " << std::endl;
    std::cin >> temperature[0];
    std::cout << "enter warm " << std::endl;
    std::cin >> warm;
    std::cout << "\n";

    if (temp == 1) {
        linear_transformation(temperature, warm, a, b);
        for (int i = 0; i < N; i++) {
            std::cout << "y[" << i << "]=" << temperature[i] << std::endl;
        }
    }
    else {
        nonlinear_transformation(temperature, warm, a, b, c, d);
        for (int i = 0; i < N; i++) {
            std::cout << "y[" << i << "]=" << temperature[i] << std::endl;
        }
    }

    return 0;
}

int main() {
    choose_transformation();

    system("pause");
    return 0;
}
