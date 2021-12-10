
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
    coefs = user_setup.poly_coefs_y;

    RHS = [&]( const double y,const double t,const double x){return user_setup.RHS( coefs, y, t, x);};
    y_short_term = E::ArrayXd(1);
    sampling_frequency = user_setup.sampling_frequency;

    // Filling the first entry of y_short_term
    y_short_term(0) = user_setup.y[0];
}

E::ArrayXd ODE::Solve(SetUp &user_setup) {

    method_length = GetMethodLength();
    if (method_length != 1) {
        InitializeYShortTerm();
    }
    std::cout << "before YSTdocumentaion\n";
    DocumentYShortTerm();
    std::cout << "after YST documentaion\n"<<std::flush;
    double y_new;
    for (int iteration = method_length; iteration <= N; iteration++) {
        y_new = OneStep(iteration * dt + t_0);

        if ((iteration) % sampling_frequency == 0) {
            y[(iteration) / sampling_frequency] = y_new;
        }

        UpdateYShortTerm(y_new);
    }
    return y;
}

void ODE::DocumentYShortTerm() {

    if (sampling_frequency < method_length) {
        for (int init_count = 1; init_count < method_length; init_count++) {
            if (init_count % sampling_frequency == 0) {
                y[init_count / sampling_frequency] = y_short_term(init_count);
            }
        }
    }

}


void ODE::UpdateYShortTerm(double y_new){

    if (method_length == 1) {
        y_short_term(0) = y_new;
    }

    else {
        y_short_term(y_short_term(E::seq(0, method_length - 2))) = y_short_term(E::seq(1, method_length - 1));
        y_short_term(method_length - 1) = y_new;
    };
}