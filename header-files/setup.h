//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H

#include "Eigen/Dense"


#include <string> // TODO Delete if no longer necessary

namespace E = Eigen;

class SetUp {
public:
    int N = 50;
    double dt = 0.1;

    double x = 0.0;

    std::string method = "ForwardEuler";

    E::ArrayXd t = E::ArrayXd::LinSpaced(N+1, 0, N*dt);;

    E::ArrayXd y = E::ArrayXd::Ones(N);
    int sampling_frequency = 2;

    double RHS(double a, double b) {
        return 1;
    }
};

#endif //ODE_SOLVER_PROJECT_SETUP_H
