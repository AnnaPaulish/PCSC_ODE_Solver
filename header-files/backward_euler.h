//
// Created by Leonhard Driever on 08.12.21.
//

#ifndef ODE_SOLVER_PROJECT_BACKWARD_EULER_H
#define ODE_SOLVER_PROJECT_BACKWARD_EULER_H

#include "ode_parent.h"
#include "setup.h"

class BackwardEuler: public ODE {

public:
    BackwardEuler(SetUp user_setup);

protected:
    int method_length = 1;

    double OneStep(double t);

};

#endif //ODE_SOLVER_PROJECT_BACKWARD_EULER_H
