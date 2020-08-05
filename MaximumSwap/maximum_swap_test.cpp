/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/05
 *
 * Source : https://leetcode.com/problems/maximum-swap/
 * Problem:	Maximum Swap
 *
 */
#include <gtest/gtest.h>
#include "maximum_swap.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, maximumSwap) {
	EXPECT_EQ(solution_.maximumSwap(2736), 7236);
	EXPECT_EQ(solution_.maximumSwap(9973), 9973);
	EXPECT_EQ(solution_.maximumSwap(98368), 98863);
	EXPECT_EQ(solution_.maximumSwap(1993), 9913);
}

