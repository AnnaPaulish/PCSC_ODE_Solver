//
// Created by Leonhard Driever on 05.12.21.
//

#include 'adams_bashforth_4.h'
#include 'adams_bashforth_3.h'
#include 'setup.h'

AdamsBashforth_4::AdamsBashforth_4(SetUp user_setup) : Adams_Bashforth_3 (SetUp user_setup) {};

void AdamsBashforth_4::InitializeYShortTermAB4() {
    InitializeYShortTermAB3()
    y_short_term(3) = OneStepAB3(t_0 + 3 * dt)
}

double AdamsBashforth_4::OneStepAB4(double t) {
    // Calculating the individual components of the gradient estimation
    auto term_1 = 55 / 24 * RHS(y_short_term(3), t - dt, x);
    auto term_2 = - 59 / 24 * RHS(y_short_term(2), t - 2 * dt, x);
    auto term_3 = 37 / 24 * RHS(y_short_term(1), t - 3 * dt, x);
    auto term_4 = - 9 / 24 * RHS(y_short_term(0), t - 4 * dt, x);

    return y_short_term(3) + dt * (term_1 + term_2 + term_3 + term_4)
}