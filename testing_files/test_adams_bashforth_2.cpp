#include "gtest/gtest.h"
#include "test_forward_euler.cpp"
#include "adams_bashforth_2.cpp"

struct AdamsBashforth_2Test : ForwardEulerTest
{
    class AdamsBashforth_2* ode;
    AdamsBashforth_2Test()
    {
        ode = new AdamsBashforth_2(*test_setup);
    }
    virtual ~AdamsBashforth_2Test()
    {
        delete ode;
    }
};

TEST_F(AdamsBashforth_2Test, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};