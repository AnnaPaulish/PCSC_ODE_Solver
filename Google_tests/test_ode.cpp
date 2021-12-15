#include "ode_parent.cpp"
#include "test_setup.cpp"


// We show that our methods can solve an arbitrary ODE with nonlinear solution
// choosing y' = y + 2y^2 and y_0 = -1 at t=0 has the exact solution: y = exp(t) / (1 - 2*exp(t))

struct ODETest : SetUpTest
{
    double exact_solution;
    class SetUp solution;
    ODETest()
    {
        // Calculate the final solution, knowing that for the test setup t_0 = 0 and y_0 = -1
        auto time = test_setup->t[test_setup->t.size() - 1];
        exact_solution = std::exp(time) / (1 - 2 * std::exp(time));
    }
};
