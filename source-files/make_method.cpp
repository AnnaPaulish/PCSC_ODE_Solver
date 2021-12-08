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
        return "The provided method name does ont correspond to any of the known methods.\n Please check your spelling or try a different method";
    }
};

std::any MakeMethod(SetUp user_setup){
    std::string method = user_setup.method;

    if (method == "ForwardEuler") return ForwardEuler(user_setup);
    else if (method == "AdamsBashforth_2") return AdamsBashforth_2(user_setup);
    else if (method == "AdamsBashforth_3") return AdamsBashforth_3(user_setup);
    else if (method == "AdamsBashforth_4") return AdamsBashforth_4(user_setup);
    else if (method == "RungeKutta") return RungeKutta(user_setup);
    else if (method == "BackwardEuler") return BackwardEuler(user_setup);
    else throw MethodError();

}
