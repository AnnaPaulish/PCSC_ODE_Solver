
#include <iostream>
#include <fstream>
#include "setup.h"

struct OpeningError : public std::exception{
    const char * what () const throw () {
        return "Error opening file.";
    }
};

SetUp::SetUp(std::string settings_path) {
    settings_file_name = settings_path;
    std::cout<<"reading file...\n";
    read_file();
    std::cout<<"finished setup...\n";
}

void SetUp::read_file() {
    std::ifstream read_settings(settings_file_name);
    if (!read_settings.is_open()) {
        throw OpeningError();
    }
    read_settings >> method;

    read_settings >> t_0;
    read_settings >> y_0;
    read_settings >> N;
    read_settings >> dt;

    read_settings >> sampling_frequency;

    if (sampling_frequency > N) sampling_frequency = N;

    read_settings >> polynomial_degree;

    solution_size = int(std::floor((N+1)/sampling_frequency)) + 1;

    t = E::ArrayXd::LinSpaced(solution_size, t_0, N*dt + t_0);
    poly_coefs_y = E::ArrayXd::Ones(polynomial_degree + 1);

    for (int i=0; i<(polynomial_degree + 1); i++){
        read_settings >> poly_coefs_y[i];
    }

    read_settings >> console_output;
    read_settings >> output_path;

    read_settings.close();
}

double SetUp::RHS(E::ArrayXd coefs, const double y_value, const double t_value, const double x_value) {

    double rhs = coefs[0];
    for (int i=1; i<(coefs.size()); i++){
        rhs += pow(y_value, i) * coefs[i];
    }
    return rhs;
}
