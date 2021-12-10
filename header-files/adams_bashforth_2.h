//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H

#include "forward_euler.h"
#include "setup.h"

class AdamsBashforth_2: public ForwardEuler {

public:
    AdamsBashforth_2(SetUp &user_setup);

protected:
    int method_length = 2;

    void InitializeYShortTermAB2();
    void InitializeYShortTerm() {this->InitializeYShortTermAB2();};

    double OneStepAB2(double t);
    double OneStep(double t) {return this->OneStepAB2(t);};

    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H
