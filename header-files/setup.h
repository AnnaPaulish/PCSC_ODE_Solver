
#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H

#include "string"
#include <Eigen/Dense>
namespace E = Eigen;

class SetUp {
public:
    // Constructor and destructor
    Set(std::string file_name);

    int N = 5; // total number of steps N
    double dt = 0.1; // time step dt

    E::ArrayXd t = E::ArrayXd::LinSpaced(N+1, 0, N*dt);
    E::ArrayXd y = E::ArrayXd::Ones(N);

    int polynomial_degree = 1; 
    E::ArrayXd poly_coefs_y = E::ArrayXd::Ones(polynomial_degree+1);

    int sampling_frequency = 2;

    double RHS(double y_value, double t_value, double x_value);

    std::string output_path; // Output File Path: path/my_output.dat
    bool console_output; // True if we want to get the result in Console
    std::string method; // solving method (string without quotation marks)

    bool testing; // True if we want to test

    // methods
    void read_settings(std::string settings_file_name);
    void read_command_line();
    void read_file(std::string settings_file_name);
    void read_console();

private:
    double t_0; // initial time
    double y_0; // initial y value

    void make_t();

};



#endif //ODE_SOLVER_PROJECT_SETUP_H
