//
// Created by Leonhard Driever on 05.12.21.
//

#include "adams_bashforth_3.h"
#include "adams_bashforth_2.h"
#include "setup.h"

AdamsBashforth_3::AdamsBashforth_3(SetUp user_setup) : Adams_Bashforth_2 (SetUp user_setup) {};

void AdamsBashforth_3::InitializeYShortTermAB3() {
    InitializeYShortTermAB2()
    y_short_term(2) = OneStepAB2(t_0 + 2 * dt)
}

void AdamsBashforth_3::InitializeYShortTerm() {
    this->InitializeYShortTermAB3()
}

double AdamsBashforth_3::OneStepAB3(double t) {
    // Calculating the individual components of the gradient estimation
    auto term_1 = 23 / 12 * RHS(y_short_term(2), t - dt, x);
    auto term_2 = - 16 / 12 * RHS(y_short_term(1), t - 2 * dt, x);
    auto term_3 = 5 / 12 * RHS(y_short_term(0), t - 3 * dt, x);

    return y_short_term(2) + dt * (term_1 + term_2 + term_3)
}

double AdamsBashforth_3::OneStep(double t) {
    return this->OneStepAB3(t)
}