//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H

#include "adams_bashforth_3.h"
#include 'setup.h'

class AdamsBashforth_4: public AdamsBashforth_3 {

public:
    AdamsBashforth_4(SetUp user_setup);

protected:
    int method_length = 4;

    void InitializeYShortTermAB4();
    void InitializeYShortTerm = &InitializeYShortTermAB4;

    double OneStepAB4(double t, double x);
    double OneStep = &one_step_AB4;

};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H
