class NonlinearModel {
private:
    double a, b, c, d;
public:
    NonlinearModel(double a, double b, double c, double d);
    
    double get_a();
    double get_b();
    double get_c();
    double get_d();

    void set_a(double _a);
    void set_b(double _b);
    void set_c(double _c);
    void set_d(double _d);

    double simulate_temperature(double Yt, double PreYt, double Uw, double PreUw);
};