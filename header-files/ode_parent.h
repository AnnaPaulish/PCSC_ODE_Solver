//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ODE_CLASS_H
#define ODE_SOLVER_PROJECT_ODE_CLASS_H

#include <Eigen/Dense>
#include "setup.h"

namespace E = Eigen;

class ODE{

public:
    explicit ODE(SetUp user_setup);
    void Solve();

    virtual ~ODE(){};

protected:
    double dt;
    double t_0;
    double x;
    int N;
    int method_length;
    E::ArrayXd y_short_term;
    E::ArrayXd &y;
    E::ArrayXd t;

    std::function<double (const double,const double,const double)> RHS;
    virtual void InitializeYShortTerm() {};
    virtual double OneStep(double t) = 0;
    virtual int GetMethodLength() = 0;

private:
    int sampling_frequency;

    void DocumentYShortTerm();
    void UpdateYShortTerm(double y_new);

};

#endif //ODE_SOLVER_PROJECT_ODE_CLASS_H
