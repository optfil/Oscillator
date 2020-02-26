#include "dynsystem.h"

DynSystem::DynSystem(double m, double gamma, double k, double x0, double v0, double t, double dt):
    m_(m), gamma_(gamma), k_(k), x_(x0), v_(v0), t_(t), dt_(dt)
{}
