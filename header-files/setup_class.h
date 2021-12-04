//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_SETUP_CLASS_H
#define ODE_SOLVER_PROJECT_SETUP_CLASS_H

class SetUp {
    int t = 0;

    double RHS(double a, double b) {
        return a + b;
    }
};

#endif //ODE_SOLVER_PROJECT_SETUP_CLASS_H
