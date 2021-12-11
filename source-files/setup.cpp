
#include <iostream>
#include <fstream>
#include "setup.h"

SetUp::SetUp(std::string settings_path) {
    settings_file_name = settings_path;
    read_settings();
    make_t();
}
void SetUp::read_file() {
    std::ifstream read_settings(settings_file_name);
    if (!read_settings.is_open()) {
        std::cout << "Error opening file." << std::endl;
    }
    read_settings >> method;
    read_settings >> t_0;
    read_settings >> y_0;

    read_settings >> N;

    read_settings >> dt;
    read_settings >> sampling_frequency;
    read_settings >> polynomial_degree;

    solution_size = int(std::floor((N+1)/sampling_frequency)) + 1;

    t.resize(solution_size);

    t[0]=t_0;

    poly_coefs_y = E::ArrayXd::Ones(polynomial_degree + 1);

    for (int i=0; i<(polynomial_degree + 1); i++){
        read_settings >> poly_coefs_y[i];
    }

    read_settings >> console_output;
    read_settings >> output_path;
    read_settings >> testing;
    read_settings.close();
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
void SetUp::read_settings() {
    std::string settings_file_name = "set.txt";
    if (settings_file_name == ""){
        std::cout<<"reading console...\n";
        read_console();
    }
    else{
        std::cout<<"reading file...\n";
        read_file();
    }
}

double SetUp::RHS(E::ArrayXd coefs, const double y_value, const double t_value, const double x_value) {

    double rhs = coefs[0];
    for (int i=1; i<(coefs.size()); i++){
        rhs += pow(y_value, i) * coefs[i];
    }
    return rhs;
}
void SetUp::make_t() {

    t[0] = t_0;

    for (int i=1; i<(solution_size); i++){
        t[i] = i * sampling_frequency * dt;
    }
    std::cout << "finished setup..." << std::endl;
}
