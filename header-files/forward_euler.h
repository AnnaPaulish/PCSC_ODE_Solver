//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_FORWARD_EULER_H
#define ODE_SOLVER_PROJECT_FORWARD_EULER_H

#include "ode_parent.h"
#include 'setup.h'

class ForwardEuler: public ODE {

public:
    ForwardEuler(SetUp UserSetUP);

protected:
    int method_length = 1;

    double OneStepFE(double t, double x);
    double OneStep = &one_step_FE;

};

#endif //ODE_SOLVER_PROJECT_FORWARD_EULER_H
