#include <iostream>
#include <cmath>
#include <fstream>

class Model {
public:
    virtual float calculate_output(float current_output, float control_input) = 0;
    virtual ~Model() = default;
};

class LinearModel : public Model {
private:
    float parameter_a;
    float parameter_b;
    float previous_output;

public:
    LinearModel(float a, float b, float initial_output)
        : parameter_a(a), parameter_b(b), previous_output(initial_output) {}

    float calculate_output(float current_output, float control_input) override {
        previous_output = parameter_a * current_output + parameter_b * control_input;
        return previous_output;
    }

    ~LinearModel() override = default;
};

class NonlinearModel : public Model {
private:
    float parameter_a;
    float parameter_b;
    float parameter_c;
    float parameter_d;
    float previous_output = 0;
    float previous_control_input = 0;

public:
    NonlinearModel(float a, float b, float c, float d, float initial_output)
        : parameter_a(a), parameter_b(b), parameter_c(c), parameter_d(d), previous_output(initial_output) {}

    float calculate_output(float current_output, float control_input) override {
        float calculated_output = parameter_a * current_output - parameter_b * std::pow(previous_output, 2) + parameter_c * control_input + parameter_d * std::sin(previous_control_input);
        previous_output = current_output;
        previous_control_input = control_input;
        return calculated_output;
    }

    ~NonlinearModel() override = default;
};

class PIDController {
private:
    float T;
    float T0;
    float TD;
    float K;
    float control_input = 0;

public:
    PIDController(float T, float T0, float TD, float K)
        : T(T), T0(T0), TD(TD), K(K) {}

    float calculate_control_input(float error, float previous_error, float previous_previous_error) {
        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        control_input += q0 * error + q1 * previous_error + q2 * previous_previous_error;
        return control_input;
    }
};

void simulate_pid_controller(float desired_value, float initial_output, PIDController& controller, Model& model) {
    std::ofstream fout("PID.txt", std::ios_base::out | std::ios_base::app);
    if (fout.is_open()) {
        float previous_error = 0;
        float previous_previous_error = 0;
        float output = initial_output;

        for (int i = 0; i < 100; i++) {
            float error = desired_value - output;
            float control_input = controller.calculate_control_input(error, previous_error, previous_previous_error);
            output = model.calculate_output(initial_output, control_input);

            fout << "E=" << error << " Y=" << output << " U=" << control_input << std::endl;

            previous_previous_error = previous_error;
            previous_error = error;
        }
    }
    fout.close();
}

int main() {
    std::ofstream fout("PID.txt", std::ios_base::out | std::ios_base::app);
    if (fout.is_open()) {
        fout << "Linear Model:" << std::endl;
        LinearModel linear_model(0.333f, 0.667f, 1);
        PIDController linear_controller(10, 10, 50, 0.1f);
        simulate_pid_controller(5, 2, linear_controller, linear_model);

        fout << "Nonlinear Model:" << std::endl;
        NonlinearModel nonlinear_model(1.0f, 0.0033f, 0.525f, 0.525f, 1.0f);
        PIDController nonlinear_controller(10, 10, 50, 0.1f);
        simulate_pid_controller(5, 2, nonlinear_controller, nonlinear_model);
    }
    std::cout << "Data has been saved to the PID.txt file" << std::endl;
    return 0;
}