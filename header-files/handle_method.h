
#ifndef ODE_SOLVER_PROJECT_HANDLE_METHOD_H
#define ODE_SOLVER_PROJECT_HANDLE_METHOD_H

#include "ode_parent.h"

/**
* Retuns a pointer to a child of the ODE class corresponding to a specific solution method 
*/

ODE* MakeMethod(SetUp user_setup);

void RemoveMethod(ODE* ode_pointr);

#endif //ODE_SOLVER_PROJECT_HANDLE_METHOD_H
