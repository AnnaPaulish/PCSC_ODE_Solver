#ifndef ODE_SOLVER_PROJECT_WRITE_OUTPUT_CLASS_H
#define ODE_SOLVER_PROJECT_WRITE_OUTPUT_CLASS_H

#include "setup.h"
#include "string"
#include <Eigen/Dense>
namespace E = Eigen;

class Output {
public:
    // Constructor and destructor
    Output(SetUp user_setup);
    void write();

private:
    bool console_output;
    std::string output_path;
    E::ArrayXd *y;
    E::ArrayXd *t;

    void write_file(std::string path);
    void write_to_screen();


};


#endif //ODE_SOLVER_PROJECT_WRITE_OUTPUT_CLASS_H
