//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ODE_CLASS_H
#define ODE_SOLVER_PROJECT_ODE_CLASS_H

#include <Eigen/Dense>
#include 'setup_class.h'

namespace E = Eigen;

class ODE{

public:
    explicit ODE(SetUp UserSetUp);
    void solve();

protected:
    const double dt;
    const int N
    const int method_length;
    E::Array<double, method_length, 1> y_short_term; // Static size is applicable as it is dependent on the method and does not change
    E::ArrayXd & y;
    const E::ArrayXd & t;

    double RHS;
    virtual void initialize_y_short_term() = 0;
    virtual double one_step() = 0;

private:
    const int sampling_frequency;

    void document_y_short_term()
    void update_y_short_term(double y_new);

};

#endif //ODE_SOLVER_PROJECT_ODE_CLASS_H
