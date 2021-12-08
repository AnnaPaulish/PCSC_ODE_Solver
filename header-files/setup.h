//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_SETUP_H
#define ODE_SOLVER_PROJECT_SETUP_H
class SetUp {
public:
    // Constructor and destructor
    Set(std::string file_name);

    int N = 5; // total number of steps N
    double dt = 0.1; // time step dt
    double x = 0.0;
    Eigen::ArrayXd t = Eigen::ArrayXd::LinSpaced(N+1, 0, N*dt);
    Eigen::ArrayXd y = Eigen::ArrayXd::Ones(N);

    int polynomial_degree = 1; //
    Eigen::ArrayXd poly_coefs_y = Eigen::ArrayXd::Ones(polynomial_degree+1);

    int sampling_frequency = 2;

    double RHS(double y_value, double t_value, double x_value);

    std::string output_path; // Output File Path: path/my_output.dat
    bool console_output; // True if we want to get the result in Console
    //bool console_input;
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
