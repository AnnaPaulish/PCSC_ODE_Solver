#include "gtest/gtest.h"
#include "runge_kutta.cpp"

#ifndef TEST_ODE_CPP
#include "test_ode.cpp"
#endif

struct RungeKuttaTest : ODETest
{
    class RungeKutta* ode;
    RungeKuttaTest()
    {
        ode = new RungeKutta(*test_setup);
    }
    virtual ~RungeKuttaTest()
    {
        delete ode;
    }
};

TEST_F(RungeKuttaTest, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};