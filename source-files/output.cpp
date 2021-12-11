

#include <iostream>
#include <fstream>
#include "output.h"
#include "setup.h"

Output::Output(SetUp user_setup, E::ArrayXd& solution) {

    console_output = user_setup.console_output;
    output_path = user_setup.output_path;
    t = user_setup.t;
    y = solution;
}

void Output::write() {

    if (console_output){
        write_to_screen();
    }

    if (output_path != "None"){
        write_file(output_path);
    }
}

void Output::write_file(std::string path){

    std::ofstream output_file(path);
    // Check that file is properly opened.
    if (!output_file.is_open()) {
        std::cout << "Error opening output file." << std::endl;
    }

    output_file.precision(4);
    output_file.setf(std::ios::scientific);
    output_file.setf(std::ios::showpos);

    for (int i = 0; i < y.size(); i++){
        output_file << t[i] << " " << y[i] << std::endl;
    }

    output_file.flush();
    output_file.close();
}

void Output::write_to_screen() {

    std::cout << std::scientific;
    std::cout << std::showpos;
    std::cout << std::setprecision(4);

    std::cout << "\nSolution of ODE: \n";
    std::cout << "Time" << "\t\t\ty-value\n";

    for (int i = 0; i < y.size(); i++){
        std::cout << t[i] << "\t\t" << y[i] << std::endl;
    }
}