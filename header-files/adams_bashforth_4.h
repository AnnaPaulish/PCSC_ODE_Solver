//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H

#include "adams_bashforth_3.h"
#include "setup.h"

class AdamsBashforth_4: public AdamsBashforth_3 {

public:
    AdamsBashforth_4(SetUp user_setup);

protected:
    const int method_length = 4;

    void InitializeYShortTermAB4();
    void InitializeYShortTerm();

    double OneStepAB4(double t);
    double OneStep(double t);

};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H
