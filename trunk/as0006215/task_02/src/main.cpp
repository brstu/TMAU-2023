#include <iostream>
#include <cmath>

// Базовый класс математической модели
class MathModel {
public:
    /**
     * @brief Расчет выходного значения модели
     * @param Yt Текущее значение
     * @param Yt_1 Предыдущее значение
     * @param U Входное значение
     * @return Выходное значение модели
     */
    virtual double calculateOutput(double Yt, double Yt_1, double U) const = 0;
     virtual ~MathModel() = default;
};

// Линейная модель
class LinearModel : public MathModel {
private:
    double a;
    double b;

public:
    /**
     * @brief Конструктор линейной модели
     * @param a Параметр a
     * @param b Параметр b
     */
    explicit LinearModel(double a, double b) : a(a), b(b) {}

    double calculateOutput(double Yt, double Yt_1, double U) const override {
        return a * Yt + b * U;
    }
};

// Нелинейная модель
class NonlinearModel : public MathModel {
private:
    double a;
    double b;
    double c;
    double d;

public:
    /**
     * @brief Конструктор нелинейной модели
     * @param a Параметр a
     * @param b Параметр b
     * @param c Параметр c
     * @param d Параметр d
     */
    NonlinearModel(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    double calculateOutput(double Yt, double Yt_1, double U) const override {
        return a * Yt - b * std::pow(Yt_1, 2) + c * U + d * std::sin(U);
    }
};

// ПИД-регулятор
class PIDController {
private:
    double q0;
    double q1;
    double q2;
    double e_k_1 = 0.0;
    double e_k_2 = 0.0;
    double u_k_1 = 0.0;

public:
    /**
     * @brief Конструктор ПИД-регулятора
     * @param k Параметр k
     * @param TD Параметр TD
     * @param T0 Параметр T0
     */
    explicit PIDController(double k, double TD, double T0) : q0(k * (1 + (TD / T0))), q1(-k * (1 + 2 * (TD / T0) - (T0 / TD))),
                                                            q2(k * (TD / T0)) {}

    /**
     * @brief Расчет выходного значения ПИД-регулятора
     * @param e_k Ошибка
     * @return Выходное значение ПИД-регулятора
     */
    double calculateOutput(double e_k) {
        double u_k = u_k_1 + q0 * e_k + q1 * e_k_1 + q2 * e_k_2;
        u_k_1 = u_k;
        e_k_2 = e_k_1;
        e_k_1 = e_k;
        return u_k;
    }
};

int main() {
    double a_linear = 0.8;
    double b_linear = 0.5;
    double a_nonlinear = 0.8;
    double b_nonlinear = 0.5;
    double c_nonlinear = 0.2;
    double d_nonlinear = 0.1;

    double Y_linear = 0.0;
    double Y_nonlinear = 0.0;
    double Y_prev_nonlinear = 0.0;

    // Входные значения
    double U = 1.0;

    // Создание объектов моделей
    LinearModel linearModel(a_linear, b_linear);
    NonlinearModel nonlinearModel(a_nonlinear, b_nonlinear, c_nonlinear, d_nonlinear);

    // ПИД-регулятор
    PIDController pidController(1.0, 0.5, 0.2);

    // Симуляция на 10 временных шагов
    for (int t = 1; t <= 10; t++) {
        // Линейная модель
         double Yt_linear = linearModel.calculateOutput(Y_linear, 0, U);

        // Нелинейная модель
        double Yt_nonlinear = nonlinearModel.calculateOutput(Y_nonlinear, Y_prev_nonlinear, U);
        Y_prev_nonlinear = Y_nonlinear;
        Y_nonlinear = Yt_nonlinear;

        // ПИД-регулятор
        double error = Yt_linear - Yt_nonlinear;
        double controlSignal = pidController.calculateOutput(error);

        // Вывод результатов
        std::cout << "Time step: " << t << std::endl;
        std::cout << "Linear model output: " << Yt_linear << std::endl;
        std::cout << "Nonlinear model output: " << Yt_nonlinear << std::endl;
        std::cout << "Error: " << error << std::endl;
        std::cout << "Control signal: " << controlSignal << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
