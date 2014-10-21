#include <gtest/gtest.h>
#include "string_to_integer.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.atoi("0"), 0);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.atoi("-0"), 0);
}

TEST_F(SolutionTest, case3) {
	EXPECT_EQ(solution_.atoi("+10"), 10);
}

TEST_F(SolutionTest, case4) {
	EXPECT_EQ(solution_.atoi("-1230"), -1230);
}

TEST_F(SolutionTest, case5) {
	EXPECT_EQ(solution_.atoi("120"), 120);
}

TEST_F(SolutionTest, case6) {
	EXPECT_EQ(solution_.atoi(""), 0);
}

TEST_F(SolutionTest, case7) {
	EXPECT_EQ(solution_.atoi("+-2"), 0);
}

TEST_F(SolutionTest, case8) {
	EXPECT_EQ(solution_.atoi("    010"), 10);
}

TEST_F(SolutionTest, case9) {
	EXPECT_EQ(solution_.atoi("     +004500"), 4500);
}

TEST_F(SolutionTest, case10) {
	EXPECT_EQ(solution_.atoi("  -0012a42"), -12);
}

TEST_F(SolutionTest, case11) {
	EXPECT_EQ(solution_.atoi("2147483648"), 2147483647);
}

TEST_F(SolutionTest, case12) {
	EXPECT_EQ(solution_.atoi("-2147483648"), -2147483648);
}

TEST_F(SolutionTest, case13) {
	EXPECT_EQ(solution_.atoi("-2147483649"), -2147483648);
}

TEST_F(SolutionTest, case14) {
	EXPECT_EQ(solution_.atoi("      -11919730356x"), -2147483648);
}

TEST_F(SolutionTest, case15) {
	EXPECT_EQ(solution_.atoi(" b11228552307"), 0);
}

TEST_F(SolutionTest, case16) {
	EXPECT_EQ(solution_.atoi("    10522545459"), 2147483647);
}

