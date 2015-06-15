/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/15
 *
 * Source : https://leetcode.com/problems/factorial-trailing-zeroes/
 * Problem:	Factorial Trailing Zeroes 
 *
 */
#include <gtest/gtest.h>
#include "factorial_trailing_zeroes.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.trailingZeroes(5), 1);
	EXPECT_EQ(solution_.trailingZeroes(7), 1);
	EXPECT_EQ(solution_.trailingZeroes(10), 2);
	EXPECT_EQ(solution_.trailingZeroes(12), 2);
	EXPECT_EQ(solution_.trailingZeroes(15), 3);
	EXPECT_EQ(solution_.trailingZeroes(18), 3);
	EXPECT_EQ(solution_.trailingZeroes(20), 4);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.trailingZeroes(25), 6);
	EXPECT_EQ(solution_.trailingZeroes(50), 12);
	EXPECT_EQ(solution_.trailingZeroes(75), 18);
	EXPECT_EQ(solution_.trailingZeroes(100), 24);
	EXPECT_EQ(solution_.trailingZeroes(125), 31);
	EXPECT_EQ(solution_.trailingZeroes(1000), 249);
}

TEST_F(SolutionTest, case3) {
	EXPECT_EQ(solution_.trailingZeroes(INT32_MAX), 536870902);
}

