
#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H
#include "string"
#include <Eigen/Dense>
namespace E = Eigen;
class SetUp {
public:
    // Constructor and destructor
    SetUp();

    int N = 5; // total number of steps N
    double dt = 0.1; // time step dt
    double x = 0;
    int polynomial_degree = 1; //
    E::ArrayXd poly_coefs_y;


    int sampling_frequency = 2;

    E::ArrayXd t = E::ArrayXd::LinSpaced(solution_size, 0, solution_size*dt);// todo adjust for the sampling frequency
    E::ArrayXd y = E::ArrayXd::Ones(solution_size);

    std::string output_path; // Output File Path: path/my_output.dat
    bool console_output; // True if we want to get the result in Console
    //bool console_input;
    std::string method; // solving method (string without quotation marks)

    bool testing; // True if we want to test
    // methods
    void read_settings();
    void read_file(std::string settings_file_name);
    void read_console();

    double RHS(E::ArrayXd coefs, const double y_value, const double t_value, const double x_value);

private:
    double t_0; // initial time
    double y_0; // initial y value
    int solution_size;


    void make_t();


};

#endif //ODE_SOLVER_PROJECT_SETUP_H
