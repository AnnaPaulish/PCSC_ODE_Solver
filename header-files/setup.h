
#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H
#include "string"
#include <Eigen/Dense>
namespace E = Eigen;
class SetUp {
public:
    // Constructor and destructor
    SetUp(std::string settings_path="settings.txt");

    int N = 5; // total number of steps N
    double dt = 0.1; // time step dt
    double x = 0;
    int polynomial_degree = 1; //
    E::ArrayXd poly_coefs_y;
    double y_0; // initial y value
    int solution_size;
    int sampling_frequency = 2;

    E::ArrayXd t = E::ArrayXd::LinSpaced(solution_size, 0, solution_size*dt);

    std::string output_path; // Output File Path: path/my_output.dat
    bool console_output; // True if we want to get the result in Console
    std::string method; // solving method (string without quotation marks)

    bool testing; // True if we want to test
    // methods
    void read_settings();
    void read_file();
    void read_console();

    double RHS(E::ArrayXd coefs, const double y_value, const double t_value, const double x_value);

private:
    double t_0; // initial time
    std::string settings_file_name;
    void make_t();


};

#endif //ODE_SOLVER_PROJECT_SETUP_H
