/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/12
 *
 * Source : https://oj.leetcode.com/problems/min-stack/
 * Problem:	Min Stack
 *
 */
#include <gtest/gtest.h>
#include "min_stack.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        MinStack solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(1, 1);
}

