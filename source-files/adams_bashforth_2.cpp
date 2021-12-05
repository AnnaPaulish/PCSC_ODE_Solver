//
// Created by Leonhard Driever on 05.12.21.
//

#include 'adams_bashforth_2.h'
#include 'forward_euler.h'
#include 'setup.h'

AdamsBashforth_2::AdamsBashforth_2(SetUp UserSetUp) : ForwardEuler (SetUp UserSetUp) {};

void AdamsBashforth_2::InitializeYShortTermAB2() {
    y_short_term(1) = OneStepFE(y_short_term(0), t_0 + dt, x)
}

double AdamsBashforth_2::OneStepAB2(double t, double x) {
    return y_short_term(1) + dt * (3 / 2 * RHS(y_short_term(1), t - dt, x) - 1 / 2 * RHS(y_short_term(0), t - 2 * dt, x));
}