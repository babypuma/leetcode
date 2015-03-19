/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/single-number/
 * Problem:	Single Number
 *               
 */
#include <gtest/gtest.h>
#include "single_number.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 5, 8, 5, 7, 8, 1};
	EXPECT_EQ(solution_.singleNumber(a, sizeof(a)/sizeof(int)), 7);
}

