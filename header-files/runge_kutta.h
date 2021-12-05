//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_RUNGE_KUTTA_H
#define ODE_SOLVER_PROJECT_RUNGE_KUTTA_H

#include "ode_parent.h"
#include 'setup.h'

class RungeKutta: public ODE {

public:
    RungeKutta(SetUp UserSetUP);

protected:
    int method_length = 1;

    double OneStep(double t);

};

#endif //ODE_SOLVER_PROJECT_RUNGE_KUTTA_H
