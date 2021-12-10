

#include <iostream>
#include <fstream>
#include "output.h"
#include "setup.h"

Output::Output(SetUp user_setup) {

    console_output = user_setup.console_output;
    output_path = user_setup.output_path;
    t = &user_setup.t;
    y = &user_setup.y;
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

    for (int i = 0; i < y->size(); i++){
        output_file << t[0][i] << " " << y[0][i] << std::endl;
    }

    output_file << 1 << " " << 2 << std::endl;

    output_file.flush();
    output_file.close();
}

void Output::write_to_screen() {

    std::cout << std::scientific;
    std::cout << std::showpos;
    std::cout << std::setprecision(4);

    std::cout << "Solution of ODE: \n";
    std::cout << "Time" << "\t\t\ty-value\n";

    for (int i = 0; i < y->size(); i++){
        std::cout << t[0][i] << "\t\t" << y[0][i] << std::endl;
    }
}