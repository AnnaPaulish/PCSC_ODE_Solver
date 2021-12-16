
#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H
#include "string"
#include <Eigen/Dense>
namespace E = Eigen;

/**
 * This is a SetUp class to initialization of all input parameters
 */
class SetUp {
public:
    /// Constructor
    SetUp(std::string settings_path="../settings.txt");

    int N; /// total number of steps N
    double dt; /// time step dt
    double x;
    int polynomial_degree; /// the degree of the polynomial on the right side of the ODE
    E::ArrayXd poly_coefs_y; ///  the coefficients of the polynomial on the right side of the ODE starting from degree zero
    E::ArrayXd t; /// time array
    double y_0; /// initial y value
    int solution_size; /// number of elements in the solution array y
    int sampling_frequency; /// parameter to shorten the output. For example, you can output every third element of the solution (in this case sampling_frequency = 3). Define sampling_frequency = 1 to show the entire solution

    std::string output_path; /// Output file name: output.txt
    bool console_output; // True if we want to get the result in Console
    std::string method; // solving method (string without quotation marks)

    bool testing; /// True if we want to test
    /// method for reading the settings
    void read_file();
    /// method for calculating the RHS of ODE
    double RHS(E::ArrayXd coefs, const double y_value, const double t_value, const double x_value);

private:
    double t_0; /// initial time value
    std::string settings_file_name; /// the name of the input file with the initial parameters of ODE
};

#endif //ODE_SOLVER_PROJECT_SETUP_H