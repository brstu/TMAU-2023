class LinearModel {
private:
    double a, b;
public:
    LinearModel(double a, double b);
    
    double get_a();
    double get_b();

    void set_a(double _a);
    void set_b(double _b);
    
    double simulate_temperature(double Yt, double Uw);
};