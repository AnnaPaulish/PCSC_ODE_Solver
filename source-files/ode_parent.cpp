//
// Created by Leonhard Driever on 03.12.21.
//

#include "ode_parent.h"
#include "setup.h"

ODE::ODE(SetUp user_setup) {

    // Declaring all the members
    t = &user_setup.t;
    t_0 = t[0];
    y = &user_setup.y;
    dt = user_setup.dt;
    N = user_setup.N;
    x = user_setup.x;
    RHS = &user_setup.RHS;
    sampling_frequency = &user_setup.sampling_frequency;

    // Filling the first entry of y_short_term
    y_short_term[0] = y[0]
}

void ODE::Solve() {
    if (method_length != 1) {
        initialize_y_short_term()
    }

    document_y_short_term();

    for (int iteration = method_length; iteration <= N; iteration++) {
        y_new = one_step(iteration * dt + t_0);

        update_y_short_term(y_new);

        if (iteration % sampling_frequency) {
            y(iteration / sampling_frequency) = y_new
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

    if (method_length == 1) {
        y_short_term(0) = y_new;
    }

    else {
        y_short_term(y_short_term(E::seq(0, method_length - 2))) = y_short_term(E::seq(1, method_length - 1));
        y_short_term(method_length) = y_new;
    };
}