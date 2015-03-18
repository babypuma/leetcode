#include <gtest/gtest.h>
#include "reverse_integer.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.reverse(0), 0);
	EXPECT_EQ(solution_.reverse(123), 321);
	EXPECT_EQ(solution_.reverse(-2310), -132);
	EXPECT_EQ(solution_.reverse(1000), 1);
}
