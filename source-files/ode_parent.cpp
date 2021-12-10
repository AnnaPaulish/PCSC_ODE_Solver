
#include "ode_parent.h"
#include "setup.h"

#include "iostream"

ODE::ODE(SetUp user_setup) {

    // Declaring all the members
    t = user_setup.t;
    t_0 = t[0];
    y = user_setup.y;
    dt = user_setup.dt;
    N = user_setup.N;
    x = user_setup.x;
    //RHS = [&](const double y,const double t,const double x){return user_setup.RHS(y, t, x);};
    RHS = [&](const double y,const double t,const double x){return 2;}; // Todo fix RHS and delete this line
    y_short_term = E::ArrayXd(1);
    sampling_frequency = user_setup.sampling_frequency;

    // Filling the first entry of y_short_term
    y_short_term(0) = user_setup.y[0];
}

void ODE::Solve() {
    std::cout << y_short_term;
    method_length = GetMethodLength();
    if (method_length != 1) {
        InitializeYShortTerm();
    }
    std::cout << "initialized with y_ST: " << y_short_term << std::endl;
    DocumentYShortTerm();
    double y_new;
    for (int iteration = method_length; iteration <= N; iteration++) {
        y_new = OneStep(iteration * dt + t_0);
        UpdateYShortTerm(y_new);

        if (iteration % sampling_frequency == 0) {
            y[iteration / sampling_frequency] = y_new;
        }

    }

}

void ODE::DocumentYShortTerm() {

    if (sampling_frequency < method_length) {
        for (int init_count = 1; init_count < method_length; init_count++) {
            if (init_count % sampling_frequency) {
                y(init_count / sampling_frequency) = y_short_term(init_count);
            }
        }
    }

}


void ODE::UpdateYShortTerm(double y_new){
    std::cout << "\nmade it to update YST. Method length: "<< method_length << "y_new: " << y_new <<std::endl;
    if (method_length == 1) {
        y_short_term(0) = y_new;
    }

    else {
        y_short_term(y_short_term(E::seq(0, method_length - 2))) = y_short_term(E::seq(1, method_length - 1));
        y_short_term(method_length - 1) = y_new;
    };
}