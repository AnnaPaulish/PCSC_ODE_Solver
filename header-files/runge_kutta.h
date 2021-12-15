

#ifndef ODE_SOLVER_PROJECT_RUNGE_KUTTA_H
#define ODE_SOLVER_PROJECT_RUNGE_KUTTA_H

#include "ode_parent.h"
#include "setup.h"

/**
This class is a child of the ODE class to implement the step of the Runge Kutta algorithm
*/

class RungeKutta: public ODE {

public:
    RungeKutta(SetUp &user_setup);

protected:
    int method_length = 1;

    /**
    Implements the step of the Runge Kutta algorithm
    */
    double OneStep(double t);

    /**
    Returns the required number of initial y elements needed to implement one step of the Runge Kutta algorithm
    */
    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_RUNGE_KUTTA_H
