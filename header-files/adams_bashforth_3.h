//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_3_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_3_H

#include "adams_bashforth_2.h"
#include 'setup.h'

class AdamsBashforth_3: public AdamsBashforth_2 {

public:
    AdamsBashforth_3(SetUp UserSetUP);

protected:
    int method_length = 3;

    void InitializeYShortTermAB3();
    void InitializeYShortTerm = &InitializeYShortTermAB3;

    double OneStepAB3(double t, double x);
    double OneStep = &one_step_AB3;

};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_3_H
