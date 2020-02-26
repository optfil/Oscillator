#ifndef DYNSYSTEM_H
#define DYNSYSTEM_H


class DynSystem
{
public:
    DynSystem(double m, double gamma, double k, double x0, double v0, double t, double dt);

    double m() const {return m_;}
    double gamma() const {return gamma_;}
    double k() const {return k_;}
    double x() const {return x_;}
    double v() const {return v_;}
    double t() const {return t_;}
    double dt() const {return dt_;}

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
