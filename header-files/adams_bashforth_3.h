
#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_3_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_3_H

#include "adams_bashforth_2.h"
#include "setup.h"

/**
This class is a child of the AdamsBashforth_2 class to implement the iteration of the Adams Bashforth algorithm with the step-size = 3
*/

class AdamsBashforth_3: public AdamsBashforth_2 {

public:
    AdamsBashforth_3(SetUp &user_setup);

protected:
    int method_length = 3;

    /** 
    Initializes the required number of initial y elements (3)
    needed to implement one iteration of the Adams Bashforth algorithm with the step-size = 3
    */
    void InitializeYShortTermAB3();
    void InitializeYShortTerm() {this->InitializeYShortTermAB3();};

    /**
    Implements the step of the iteration of the Adams Bashforth algorithm with the step-size = 3
    */
    double OneStepAB3(double t);
    double OneStep(double t){return this->OneStepAB3(t);};

    /**
    Returns the required number of initial y elements needed to implement one step 
    of the Adams Bashforth algorithm with the step-size = 3
    */
    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_3_H
