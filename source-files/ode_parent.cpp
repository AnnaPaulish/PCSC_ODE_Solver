#include "ode_parent.h"
#include "setup.h"
#include "iostream"

struct InfinityError : public std::exception{
    const char * what () const throw () {
        return "The differential equation diverges to infinity. Please choose a different ODE or truncate the time range within which the ODE is studied";
    }
};

ODE::ODE(SetUp &user_setup) {

    // Declaring all the members
    t = user_setup.t;
    t_0 = t[0];
    y_0 = user_setup.y_0;
    dt = user_setup.dt;
    N = user_setup.N;
    x = user_setup.x;
    coefs = user_setup.poly_coefs_y;
    y = E::ArrayXd(user_setup.solution_size);
    sampling_frequency = user_setup.sampling_frequency;

    RHS = [&]( const double y,const double t,const double x){return user_setup.RHS( coefs, y, t, x);};

    y_short_term = E::ArrayXd(1);
}

E::ArrayXd &ODE::Solve() {
    y_short_term(0) = y_0;
    method_length = GetMethodLength();
    if (method_length != 1) {
        InitializeYShortTerm();
    }

    DocumentYShortTerm();

    double y_new;
    for (int iteration = method_length; iteration <= N; iteration++) {
        y_new = OneStep(iteration * dt + t_0);

        if (isinf(y_new)) throw InfinityError();

        if ((iteration) % sampling_frequency == 0) {
            y[(iteration) / sampling_frequency] = y_new;
        }

        UpdateYShortTerm(y_new);
    }

    std::cout << "solved the ODE...\n";

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
        y_short_term(E::seq(0, method_length - 2)) = y_short_term(E::seq(1, method_length - 1));
        y_short_term(method_length - 1) = y_new;
    };
}