# PCSC_ODE_Solver
In this repository we provide implementation of different solvers for the Project 2: "Ordinary Differential Equations" of the class Programming Concepts in Scientific Computing. 

# Introduction
This project focuses on implementation of numerical methods for solving ordinary differential equations (ODEs) with a given initial value.
![image](https://user-images.githubusercontent.com/55645580/145479809-428b6218-b284-4324-b807-83d05a58b041.png)

We consider the following numerical methods:
- explicit methods: Forward Euler and the multistep Adams Bashforth (up to 4 steps);
-  implicit Backward Euler method;
-  explicit Runge-Kutta method.


# The code structure
- `CMakeLists.txt`: the main executable file is main.cpp
- `header-files\` folder contains all header files
- `sourse-files\` folder contains all source files
- `user_settings.txt` file contains all initial parameters of ODE
- `output.txt` file contains the solution of the ODE

## Input parameters
In order to solve an ordinary differential equation, you need to determine all the initial parameters using `user_settings.txt` file with the following values:
- `method_name` - a string variable without quotation marks contains the name of method. You have several options to define it:
ForwardEuler (for Forward Euler method), AdamsBashforth_2, AdamsBashforth_3, AdamsBashforth_4, RungeKutta or BackwardEuler.
- `t_0` - a double variable for initial time: 0.0 as a default
- `y_0` - a double variable for initial y value: 1.0 as a default
- `N` - an integer variable for total number of time steps: 10 as a default
- `dt` - a double variable for the time step size: 0.01 as a default
- `sampling_frequency` - an integer variable sampling frequency: 1 as a default
- `polynomial_degree` - an integer variable for the degree of the polynomial on the right side of the equation: 1 as a default
- `poly_coefs` - integers separated by spaces for the coefficients of the polynomial on the right side of the equation (starting from degree zero): 1 1 as a default == 
$$\mathbf{1*y^0 + 1*y^1}$$


## Solution

# How to run the code

# Implementation
## Structure of classes 




