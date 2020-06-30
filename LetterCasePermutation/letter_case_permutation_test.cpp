#include <gtest/gtest.h>
#include <iostream>
#include "letter_case_permutation.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<string> vec = solution_.letterCasePermutation("a1b2");
	EXPECT_EQ(vec.size(), 4);
}

