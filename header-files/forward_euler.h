//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_FORWARD_EULER_H
#define ODE_SOLVER_PROJECT_FORWARD_EULER_H

#include "ode_parent.h"
#include "setup.h"

#include "iostream"

class ForwardEuler: public ODE {

public:
    ForwardEuler(SetUp user_setup);

protected:
    int method_length = 1;

    double OneStepFE(double t);
    double OneStep(double t) {return this->OneStepFE(t);};

    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_FORWARD_EULER_H
