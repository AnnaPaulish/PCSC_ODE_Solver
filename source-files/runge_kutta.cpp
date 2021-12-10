//
// Created by Leonhard Driever on 05.12.21.
//

#include "runge_kutta.h"
#include "setup.h"

RungeKutta::RungeKutta(SetUp user_setup) : ODE (user_setup) {y_short_term.resize(method_length);};

double RungeKutta::OneStep(double t) {
    // Calculating the individual components of the step prediction
    double k1 = RHS( y_short_term(0), t - dt, x);
    double k2 = RHS( y_short_term(0) + dt * k1 / 2, t - dt / 2, x);
    double k3 = RHS( y_short_term(0) + dt * k2 / 2, t - dt / 2, x);
    double k4 = RHS( y_short_term(0) + dt * k3, t, x);

    return y_short_term(0) + dt * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}