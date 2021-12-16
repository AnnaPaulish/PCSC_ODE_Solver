

#ifndef ODE_SOLVER_PROJECT_ODE_CLASS_H
#define ODE_SOLVER_PROJECT_ODE_CLASS_H

#include <Eigen/Dense>
#include "setup.h"

namespace E = Eigen;

/**
* This is a class that solves an ordinary differential equation using one of the following methods:
* Forward Euler, Adams Bashforth (up to 4 steps),  Backward Euler or Runge-Kutta
*/

class ODE{

public:
    explicit ODE(SetUp &user_setup);
    /** 
    Constructor of the class that solves the equation using one of the numerical methods
    and returns an array with the solution
    */
    E::ArrayXd &Solve();

    virtual ~ODE(){};

protected:
    /**  time step dt */
    double dt;

    /** initial time value  */
    double t_0;

    /** independent variable of the ordinary differential equation*/ 
    double x;

    /** initial y value */
    double y_0;

    /** total number of steps N */
    int N;
    
    /** The required number of initial y elements needed to implement one step of the numerical method */
    int method_length; 

    /** An array that keeps the elements of the ODE solution */
    E::ArrayXd y;

    /** An array that keeps the required initial y elements needed to implement one step of the numerical method */
    E::ArrayXd y_short_term; 
    
    /** The coefficients of the function on the right-hand side of the ODE */
    E::ArrayXd coefs; 

    /** time array */
    E::ArrayXd t;

    /** 
    Calculates the value of the right-hand side of the ordinary differential equation
    */
    std::function<double ( const double,const double,const double)> RHS;

    /** 
    Initializes the required number of initial y elements 
    needed to implement one step of the numerical method
    */
    virtual void InitializeYShortTerm() {};

    /** 
    Implements one step of the ODE solving algorithm
    \param t Time variable
    \return The next value of y
    */
    virtual double OneStep(double t) = 0;

    /** 
    Determines how many initial elements are needed to implement a step of the numerical method
    */
    virtual int GetMethodLength() = 0;

private:
    /** Indicates the desired frequency of saving elements of the solution y */
    int sampling_frequency; 

    /** 
    If the numerical method requires more than one element to be used in the implementation step 
    then it saves the initial y elements of the solution with a given frequency
    */
    void DocumentYShortTerm();
    
    /** 
    Calculates new y_short_term values for the next step of the ODE solving algorithm
    */
    void UpdateYShortTerm(double y_new);

};

#endif //ODE_SOLVER_PROJECT_ODE_CLASS_H
