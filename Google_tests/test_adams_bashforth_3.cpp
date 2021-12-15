#include "gtest/gtest.h"
#include "test_adams_bashforth_2.cpp"
#include "adams_bashforth_3.cpp"

struct AdamsBashforth_3Test : AdamsBashforth_2Test
{
    class AdamsBashforth_3* ode;
    AdamsBashforth_3Test()
    {
        ode = new AdamsBashforth_3(*test_setup);
    }
    virtual ~AdamsBashforth_3Test()
    {
        delete ode;
    }
};

TEST_F(AdamsBashforth_3Test, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};
