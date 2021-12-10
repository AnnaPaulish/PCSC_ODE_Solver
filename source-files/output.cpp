

#include <iostream>
#include <fstream>
#include "output.h"
#include "setup.h"

Output::Output(SetUp user_setup) {
    console_output = user_setup.console_output;
    t = user_setup.t;
    y = user_setup.y;
    if (console_output){
        write_to_screen();
    }
    else{
        write_file(user_setup.output_path);
    }

}

void Output::write_file(std::string path){
    std::ofstream output_file(path);
    // Check that file is properly openened.
    if (!output_file.is_open()) {
        std::cout << "Error opening output file." << std::endl;
    }
    output_file.setf(std::ios::scientific);
    output_file.setf(std::ios::showpos);
    output_file.precision(2);
    // Write x vector ending with a new line
    for (int i = 0; i < 4; ++i) {
        output_file << y[i] << " ";
    }
    output_file << "\n";
    // Flush after writing vector y
    output_file.flush();
    output_file.close();


}
void Output::write_to_screen() {
    std::cout << "Solution of ODE: \n";
    for (int i=0;i<=y.size();i++){
        std::cout << "y["<<i<<"] = "<<y[i]<<std::endl;
    }

}