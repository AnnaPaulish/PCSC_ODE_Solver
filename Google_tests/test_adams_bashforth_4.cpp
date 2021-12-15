#include "gtest/gtest.h"
#include "test_adams_bashforth_3.cpp"
#include "adams_bashforth_4.cpp"

struct AdamsBashforth_4Test : AdamsBashforth_3Test
{
    class AdamsBashforth_4* ode;
    AdamsBashforth_4Test()
    {
        ode = new AdamsBashforth_4(*test_setup);
    }
    virtual ~AdamsBashforth_4Test()
    {
        delete ode;
    }
};

TEST_F(AdamsBashforth_4Test, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};

