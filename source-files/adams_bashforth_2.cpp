//
// Created by Leonhard Driever on 05.12.21.
//

#include "adams_bashforth_2.h"
#include "forward_euler.h"
#include "setup.h"

AdamsBashforth_2::AdamsBashforth_2(SetUp user_setup) : ForwardEuler (SetUp user_setup) {};

void AdamsBashforth_2::InitializeYShortTermAB2() {
    y_short_term(1) = OneStepFE(t_0 + dt)
}

void AdamsBashforth_2::InitializeYShortTerm() {
    this->InitializeYShortTermAB2()
}

double AdamsBashforth_2::OneStepAB2(double t) {
    // Calculating the individual components of the gradient estimation
    auto term_1 = 3 / 2 * RHS(y_short_term(1), t - dt, x);
    auto term_2 = - 1 / 2 * RHS(y_short_term(0), t - 2 * dt, x)

    return y_short_term(1) + dt * (term_1 + term_2);
}
double AdamsBashforth_2::OneStep(double t) {
    return this->OneStepAB2(t)
}