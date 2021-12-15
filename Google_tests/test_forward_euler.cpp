#include "gtest/gtest.h"
#include "forward_euler.cpp"

#ifndef TEST_ODE_CPP
#define TEST_ODE_CPP
#include "test_ode.cpp"
#endif

struct ForwardEulerTest : ODETest
{
    class ForwardEuler* ode;
    ForwardEulerTest()
    {
        ode = new ForwardEuler(*test_setup);
    }
    virtual ~ForwardEulerTest()
    {
        delete ode;
    }
};

TEST_F(ForwardEulerTest, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};