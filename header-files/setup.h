//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H

#include "Eigen/Dense"

namespace E = Eigen;

class SetUp {

    int N = 50;
    double dt = 0.1;

    double x = 0.0;

    auto t = E::ArrayXd::LinSpaced(N+1, 0, N*dt);;

    auto y = E::ArrayXD::Ones(N);
    int sampling_frequency = 2;

    double RHS(double a, double b) {
        return 1;
    }
};

#endif //ODE_SOLVER_PROJECT_SETUP_H
