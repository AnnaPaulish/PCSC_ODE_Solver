//
// Created by Leonhard Driever on 10.12.21.
//

#ifndef ODE_SOLVER_PROJECT_HANDLE_METHOD_H
#define ODE_SOLVER_PROJECT_HANDLE_METHOD_H

#include "ode_parent.h"

ODE* MakeMethod(SetUp user_setup);

void RemoveMethod(ODE* ode_pointr);

#endif //ODE_SOLVER_PROJECT_HANDLE_METHOD_H
