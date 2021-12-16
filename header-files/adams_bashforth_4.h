
#ifndef ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H
#define ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H

#include "adams_bashforth_3.h"
#include "setup.h"

/**
This class is a child of the AdamsBashforth_3 class to implement the iteration of the Adams Bashforth algorithm with the step-size = 4
*/

class AdamsBashforth_4: public AdamsBashforth_3 {

public:
    AdamsBashforth_4(SetUp &user_setup);

protected:
    /**
    Adams Bashforth algorithm with the step-size = 4 requires the knowledge of the first four elements of the y array
    */
    const int method_length = 4;

    /** 
    Initializes the required number of initial y elements (4)
    needed to implement one iteration of the Adams Bashforth algorithm with the step-size = 4
    */
    void InitializeYShortTermAB4();
    void InitializeYShortTerm() {this->InitializeYShortTermAB4();};

    /**
    Needed to implement the step of the iteration of the Adams Bashforth algorithm with the step-size = 4
    */
    double OneStepAB4(double t);
    double OneStep(double t) {return this->OneStepAB4(t);};

    /**
    Returns the required number of initial y elements needed to implement one step 
    of the Adams Bashforth algorithm with the step-size = 4
    */
    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_ADAMS_BASHFORTH_4_H
