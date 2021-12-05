//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H

#include "forward_euler.h"
#include 'setup.h'

class AdamsBashforth_2: public ODE {

public:
    AdamsBashforth_2(SetUp UserSetUP);

protected:
    int method_length = 2;

    void InitializeYShortTermAB2();
    void InitializeYShortTerm = &InitializeYShortTermAB2;

    double OneStepAB2(double t, double x);
    double OneStep = &one_step_AB_2;

};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H