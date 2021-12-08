
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <array>

#include "setup.h"
SetUp::SetUp(std::string file_name) {
    read_settings(file_name);
    make_t();
}
void SetUp::read_file(std::string settings_file_name) {
    std::ifstream read_file("set.txt");
    if (!read_file.is_open()) {
        std::cout << "Error opening file." << std::endl;
    }
    read_file >> method;
    read_file >> t_0;
    read_file >> y_0;
    read_file >> N;
    t.resize(N+1);
    y.resize(N);

    read_file >> dt;
    read_file >> sampling_frequency;
    read_file >> polynomial_degree;

    poly_coefs_y.resize(polynomial_degree+1);
    for (int i=0; i<(polynomial_degree + 1); i++){
        read_file >> poly_coefs_y[i];
    }

    read_file >> console_output;
    read_file >> output_path;
    read_file >> testing;
    read_file.close();

}
void SetUp::read_console() {
    char answer_test;
    char answer_output_format;
    std::cout<<poly_coefs_y<<std::endl;
    std::cout<<"Enter the method: ";
    std::cin>> method;

    std::cout<<"Enter initial time t0 = ";
    std::cin>> t_0;

    std::cout<<"Enter initial y value y0 = ";
    std::cin>> y_0;

    std::cout<<"Enter total number of steps N = ";
    std::cin>> N;

    std::cout<<"Enter time step dt = ";
    std::cin>> dt;

    std::cout<<"Enter sampling frequency (integer) = ";
    std::cin>> sampling_frequency;

    std::cout<<"Enter the degree of the polynomial (integer) = ";
    std::cin>> polynomial_degree;

    for (int i=0; i<(polynomial_degree + 1); i++){
        std::cout<<"Enter the coefficient of y^"<<  i << " = ";
        std::cin>> poly_coefs_y[i];
    }

    std::cout<<"Do you want to se the solution in the console? - enter y (yes) or n (no): ";
    std::cin>> answer_output_format;
    if (answer_output_format == 'y'){ console_output = true;}
    else { console_output = false;}

    if (console_output == true){
        std::cout<<"Enter output path: ";
        std::cin>> output_path;
    }
    std::cout<<"Do you want to test? - enter y (yes) or n (no): ";
    std::cin>> answer_test;
    if (answer_test == 'y'){ testing = true;}
    else { testing = false;}

}
void SetUp::read_settings(std::string settings_file_name) {
    if (settings_file_name == ""){
        std::cout<<"reading console...\n";
        read_console();
    }
    else{
        std::cout<<"reading file...\n";
        read_file(settings_file_name);
    }
}

double SetUp::RHS(double y_value, double t_value, double x_value) {
    double rhs = 0;
    for (int i=0; i<(polynomial_degree + 1); i++){
        rhs += pow(y_value, i) * poly_coefs_y[i];
    }
    return rhs;
}
void SetUp::make_t() {

    t[0] = t_0;
    for (int i=0; i<(N); i++){
        t[i+1] = (i+1)*dt;
    }
}
