#ifndef ODE_SOLVER_PROJECT_WRITE_OUTPUT_CLASS_H
#define ODE_SOLVER_PROJECT_WRITE_OUTPUT_CLASS_H

#include "setup.h"
#include "string"
#include <Eigen/Dense>
namespace E = Eigen;

/**
* This is a class that write the solution of the ordinary differential equation to the file or prints it to the console
*/

class Output {
public:
    /// Constructor of the class Output
    Output(SetUp user_setup, E::ArrayXd& solution);
    void write();

private:
    bool console_output;
    std::string output_path;
    E::ArrayXd y;
    E::ArrayXd t;

    /** Writes the solution of the ODE to the file
    \param path Specifies the path to the output file
    */
    void write_file(std::string path);

    /// Prints the solution of the ODE to the console
    void write_to_screen();


};


#endif //ODE_SOLVER_PROJECT_WRITE_OUTPUT_CLASS_H
