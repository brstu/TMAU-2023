﻿
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
    virtual double calculateOutput(double Yt, double Yt_1, double U) = 0;
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
    LinearModel(double a, double b) : a(a), b(b) {}

    double calculateOutput(double Yt, double Yt_1, double U) override {
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

    double calculateOutput(double Yt, double Yt_1, double U) override {
        return a * Yt - b * pow(Yt_1, 2) + c * U + d * sin(U);
    }
};

// ПИД-регулятор
class PIDController {
private:
    double q0;
    double q1;
    double q2;
    double e_k_1;
    double e_k_2;
    double u_k_1;

public:
    /**
     * @brief Конструктор ПИД-регулятора
     * @param k Параметр k
     * @param TD Параметр TD
     * @param T0 Параметр T0
     */
    PIDController(double k, double TD, double T0) {
        q0 = k * (1 + (TD / T0));
        q1 = -k * (1 + 2 * (TD / T0) - (T0 / TD));
        q2 = k * (TD / T0);
        e_k_1 = 0.0;
        e_k_2 = 0.0;
        u_k_1 = 0.0;
    }

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

            // Simulation for 10 time steps
            for (int t = 1; t <= 10; t++) {
                // Linear model
                double Yt_linear = linearModel.calculateOutput(Y_linear, 0.0, U);
                double e_linear = Yt_linear - Y_linear;
                double u_linear = pidController.calculateOutput(e_linear);
                Y_linear = linearModel.calculateOutput(Y_linear, 0.0, u_linear);

                // Nonlinear model
                double Yt_nonlinear = nonlinearModel.calculateOutput(Y_nonlinear, Y_prev_nonlinear, U);
                double e_nonlinear = Yt_nonlinear - Y_nonlinear;
                double u_nonlinear = pidController.calculateOutput(e_nonlinear);
                Y_nonlinear = nonlinearModel.calculateOutput(Y_nonlinear, Y_prev_nonlinear, u_nonlinear);
                Y_prev_nonlinear = Y_nonlinear;

                std::cout << "time step: " << t << std::endl;
                std::cout << "Linear model: " << Y_linear << std::endl;
                std::cout << "Nonlinear model: " << Y_nonlinear << std::endl;
                std::cout << "------------------------" << std::endl;
            }

            return 0;
        }