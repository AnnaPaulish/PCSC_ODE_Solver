
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
    /// Constructor of the SetUp class
    SetUp(std::string settings_path="../settings.txt");

   
    int N;  ///< total number of steps N

    /// time step dt 
    double dt; 

    double x;

    /// the degree of the polynomial on the right side of the ODE
    int polynomial_degree; 

    ///  the coefficients of the polynomial on the right side of the ODE starting from degree zero
    E::ArrayXd poly_coefs_y; 

    /// time array
    E::ArrayXd t; 

    /// initial y value
    double y_0; 

    /// number of elements in the solution array y
    int solution_size; 

    /// parameter to shorten the output. For example, you can output every third element of the solution (in this case sampling_frequency = 3). Define sampling_frequency = 1 to show the entire solution
    int sampling_frequency; 

    /// Output file name: output.txt
    std::string output_path; 

    /// True if we want to get the result in console
    bool console_output; 

    /// solving method (string without quotation marks)
    std::string method; 

    /// method for reading the settings
    void read_file();

    /// method for calculating the right-hand side of ODE
    double RHS(E::ArrayXd coefs, const double y_value, const double t_value, const double x_value);

private:
    /// initial time value
    double t_0; 

    /// the name of the input file with the initial parameters of ODE
    std::string settings_file_name; 
};

#endif //ODE_SOLVER_PROJECT_SETUP_H