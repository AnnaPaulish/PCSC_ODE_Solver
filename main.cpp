//
// Created by Leonhard Driever on 03.12.21.
//
#include "setup.h"
#include "output.h"
#include "make_method.cpp"
#include "output.h"

int main (int argc, char **argv) {

    auto user_setup = SetUp();

    auto ode = MakeMethod(user_setup);
    ode.solve();

    auto output = Output(user_setup);
    output.write()

    return 0;
}
