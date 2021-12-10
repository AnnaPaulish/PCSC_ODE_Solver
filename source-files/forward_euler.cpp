//
// Created by Leonhard Driever on 05.12.21.
//

#include "forward_euler.h"
#include "setup.h"

#include "iostream"

ForwardEuler::ForwardEuler(SetUp user_setup) : ODE (user_setup) {y_short_term.resize(method_length);};

double ForwardEuler::OneStepFE(double t) {//TODO variable name t shadows name in setup
    std::cout << "RHS in FE" << this->RHS(y_short_term(0), t - dt, x)<<std::flush;
    return y_short_term(0) + dt * this->RHS(y_short_term(0), t - dt, x);
}

