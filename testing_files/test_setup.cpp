#include "gtest/gtest.h"
#include "setup.cpp"

struct SetUpTest : testing::Test
{
    class SetUp* test_setup;
    SetUpTest()
    {
        test_setup = new class SetUp("../testing_files/test_settings.txt");
    }
    virtual ~SetUpTest()
    {
        delete test_setup;
    }
};

TEST_F(SetUpTest, ParametersReadCorrectly) {
    EXPECT_TRUE(test_setup->method == "RungeKutta");
    EXPECT_EQ(test_setup->t[0], 0);
    EXPECT_EQ(test_setup->y_0, -1);
    EXPECT_EQ(test_setup->N, 100);
    EXPECT_EQ(test_setup->dt, 0.01);
    EXPECT_EQ(test_setup->sampling_frequency, 2);
    EXPECT_EQ(test_setup->polynomial_degree, 2);
    EXPECT_EQ(test_setup->console_output, 1);
    EXPECT_TRUE(test_setup->output_path == "None");
};

TEST_F(SetUpTest, TArrayMadeCorrectly) {
    EXPECT_EQ(test_setup->solution_size, 51);
    EXPECT_EQ(test_setup->t.size(), 51);
};

TEST_F(SetUpTest, RHSIsCorrectFunction) {
    EXPECT_EQ(test_setup->RHS(test_setup->poly_coefs_y, 1, 0, 0), 3);
    EXPECT_EQ(test_setup->RHS(test_setup->poly_coefs_y, 2, 0, 0), 10);
};