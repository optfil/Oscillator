#ifndef DYNSYSTEM_H
#define DYNSYSTEM_H


class DynSystem
{
public:
    DynSystem(double m, double gamma, double k, double x0, double v0, double t, double dt);

private:
    double m_;
    double gamma_;
    double k_;
    double x_;
    double v_;
    double t_;
    double dt_;
};

#endif // DYNSYSTEM_H
