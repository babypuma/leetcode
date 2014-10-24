#include <gtest/gtest.h>
#include "valid_parentheses.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_TRUE(solution_.isValid("()[]{}"));
}

