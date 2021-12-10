//
// Created by Leonhard Driever on 08.12.21.
//

#include "backward_euler.h"
#include "setup.h"

BackwardEuler::BackwardEuler(SetUp user_setup) : ODE (user_setup) {y_short_term.resize(method_length);}

double BackwardEuler::OneStep(double t) {
    double residual = 1;
    double cut_off = 0.01;
    double y_next = 0;

    double y = y_short_term(0);

    while (residual > cut_off) {
        y_next = y + dt * RHS(y, t, x);
        residual = abs(y / y_next - 1);
        y = y_next;
    }

    return y_next;
}
