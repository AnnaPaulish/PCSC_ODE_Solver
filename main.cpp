//
// Created by Leonhard Driever on 03.12.21.
//
#include "setup.h"
#include "output.h"
#include "handle_method.h"

#include "iostream"

int main (int argc, char **argv) {

    auto user_setup = SetUp();
    std::cout << "finished setup" << std::endl;

    auto ode = MakeMethod(user_setup);

    std::cout << "made method" << std::endl;

    ode->Solve();

    std::cout << "solved ode" << std::endl;

    auto output = Output(user_setup);
    output.write();

    std::cout << "done with output";

    RemoveMethod(ode);

    return 0;
}
