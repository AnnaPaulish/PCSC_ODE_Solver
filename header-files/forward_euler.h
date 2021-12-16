//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_FORWARD_EULER_H
#define ODE_SOLVER_PROJECT_FORWARD_EULER_H

#include "ode_parent.h"
#include "setup.h"

#include "iostream"
/**
This class is a child of the ODE class to implement the step of the Forward Euler algorithm
*/

class ForwardEuler: public ODE {

public:
    
    ForwardEuler(SetUp &user_setup);

protected:

    /**
    Forward Euler algorithm only requires the knowledge of the initial value of the y array
    */
    int method_length = 1;

    /**
    Needed to implement the step of the Forward Euler algorithm
    */
    double OneStepFE(double t);
    double OneStep(double t) {return this->OneStepFE(t);};

    /**
    Returns the required number of initial y elements needed to implement one step of the Forward Euler algorithm
    */
    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_FORWARD_EULER_H
