//
// Created by Leonhard Driever on 04.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H

#include "forward_euler.h"
#include "setup.h"

/**
This class is a child of the ForwardEuler class to implement the iteration of the Adams Bashforth algorithm with the step-size = 2
*/

class AdamsBashforth_2: public ForwardEuler {

public:
    AdamsBashforth_2(SetUp &user_setup);

protected:
    int method_length = 2;

    /** 
    Initializes the required number of initial y elements (2)
    needed to implement one iteration of the Adams Bashforth algorithm with the step-size = 2
    */
    void InitializeYShortTermAB2();
    void InitializeYShortTerm() {this->InitializeYShortTermAB2();};

    /**
    Implements the step of the iteration of the Adams Bashforth algorithm with the step-size = 2
    */
    double OneStepAB2(double t);
    double OneStep(double t) {return this->OneStepAB2(t);};

    /**
    Returns the required number of initial y elements needed to implement one step 
    of the Adams Bashforth algorithm with the step-size = 2
    */
    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_2_H
