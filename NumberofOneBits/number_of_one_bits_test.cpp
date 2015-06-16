/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/number-of-1-bits/
 * Problem:	Number of 1 Bits
 *
 */
#include <gtest/gtest.h>
#include "number_of_one_bits.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.hammingWeight(0), 0);
	EXPECT_EQ(solution_.hammingWeight(1), 1);
	EXPECT_EQ(solution_.hammingWeight(3), 2);
	EXPECT_EQ(solution_.hammingWeight(UINT32_MAX), 32);
}

