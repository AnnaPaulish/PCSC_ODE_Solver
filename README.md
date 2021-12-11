# PCSC_ODE_Solver
In this repository we provide implementation of different solvers for the Project 2: "Ordinary Differential Equations" of the class Programming Concepts in Scientific Computing. 

# Introduction
This project focuses on implementation of numerical methods for solving ordinary differential equations (ODEs) with a given initial value.
<br/> <p align="center"> ![equation]( https://latex.codecogs.com/gif.latex?\frac{dy}{dt}=f(y,t,x)&space;\quad&space;y(t_0)=y_0) 
</p> <br/>

We consider the following numerical methods:
- explicit methods: Forward Euler and the multistep Adams Bashforth (up to 4 steps);
-  implicit Backward Euler method;
-  explicit Runge-Kutta method.


# The code structure
- `CMakeLists.txt`: the main executable file is main.cpp
- `header-files\` folder contains all header files
- `sourse-files\` folder contains all source files
- `settings.txt` file contains all initial parameters of ODE
- `output.txt` file contains the solution of the ODE after running the program

## Input parameters
In order to solve an ordinary differential equation, you need to determine all the initial parameters using `settings.txt` file with the following values:
- `method_name` - a string variable without quotation marks contains the name of method. You have several options to define it:
ForwardEuler (for Forward Euler method), AdamsBashforth_2, AdamsBashforth_3, AdamsBashforth_4, RungeKutta or BackwardEuler.
- `t_0` - a double variable for initial time: 0.0 as a default
- `y_0` - a double variable for initial y value: 1.0 as a default
- `N` - an integer variable for total number of time steps: 10 as a default
- `dt` - a double variable for the time step size: 0.01 as a default
- `sampling_frequency` - an integer variable sampling frequency: 2 as a default
- `polynomial_degree` - an integer variable for the degree of the polynomial on the right side of the equation: 1 as a default
- `poly_coefs` - integers separated by spaces for the coefficients of the polynomial on the right side of the equation starting from degree zero: 1 2 3 as a default. <br/>
The default settings correspond to: 
![equation](https://latex.codecogs.com/gif.latex?\inline&space;\quad&space;f(y,t,x)&space;=&space;1\cdot&space;y^{0}&plus;2\cdot&space;y^{1}&plus;3&space;\cdot&space;y^{2})
- `console_output` - an integer variable which indicates whether to output the solution to the console. If equal to 0 - no output in the console, 1 - solution will be printed in the console. Equal to 1 by default.
- `output_path` - a string variable without quotation marks contains the name of the output file with the solution of ODE. As a default: Output.txt
- `testing` - an integer variable which indicates whether to test the program: 0 - no testing (by default), 1 - the code will be tested.

## Solution
After executing the program, the solution of the ordinary differential equation will be written to the file specified in the `user_settings.txt` by the user or in the `Output.txt` by the default.

# How to run the code
## Requirements

# Implementation

## Structure of classes 




