//
// Created by Leonhard Driever on 05.12.21.
//

#include 'forward_euler.h'
#include 'setup.h'

ForwardEuler::ForwardEuler(SetUp UserSetUp) : ODE (SetUp UserSetUp) {};

ForwardEuler::OneStepFE() {
    return y_short_term(0) + dt * RHS(y_short_term(0), double t, double x);
}