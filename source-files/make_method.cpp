//
// Created by Leonhard Driever on 03.12.21.
//

#include "setup.h"
#include "ode_parent.h"
#include <string>
#include <any>
#include <exception>

// include method header files here
#include "forward_euler.h"
#include "adams_bashforth_2.h"
#include "adams_bashforth_3.h"
#include "adams_bashforth_4.h"
#include "runge_kutta.h"
#include "backward_euler.h"

struct MethodError : public std::exception{
    const char * what () const throw () {
        return "The provided method name does not correspond to any of the known methods.\n Please check your spelling or try a different method";
    }
};

ODE* MakeMethod(SetUp user_setup){//Todo where and how do we delete the instances
    std::string method = user_setup.method;
    ODE* ode_pointr;
    if (method == "ForwardEuler") ode_pointr = new ForwardEuler(user_setup);
    else if (method == "AdamsBashforth_2") ode_pointr = new AdamsBashforth_2(user_setup);
    else if (method == "AdamsBashforth_3") ode_pointr = new AdamsBashforth_3(user_setup);
    else if (method == "AdamsBashforth_4") ode_pointr = new AdamsBashforth_4(user_setup);
    else if (method == "RungeKutta") ode_pointr = new RungeKutta(user_setup);
    else if (method == "BackwardEuler") ode_pointr = new BackwardEuler(user_setup);
    else throw MethodError();

    return ode_pointr;
}

//void RemoveMethod()
