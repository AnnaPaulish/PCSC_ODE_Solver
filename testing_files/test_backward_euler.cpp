#include "gtest/gtest.h"
#include "backward_euler.cpp"
#ifndef TEST_ODE_CPP
#define TEST_ODE_CPP
#include "test_ode.cpp"
#endif

struct BackwardEulerTest : ODETest
{
    class BackwardEuler* ode;
    BackwardEulerTest()
    {
        ode = new BackwardEuler(*test_setup);
    }
    virtual ~BackwardEulerTest()
    {
        delete ode;
    }
};

TEST_F(BackwardEulerTest, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};