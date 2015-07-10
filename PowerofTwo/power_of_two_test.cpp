/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/10
 *
 * Source : https://leetcode.com/problems/power-of-two/
 * Problem:	Power of Two
 *
 */
#include <gtest/gtest.h>
#include "power_of_two.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_TRUE(solution_.isPowerOfTwo(1));
	EXPECT_TRUE(solution_.isPowerOfTwo(2));
	EXPECT_TRUE(solution_.isPowerOfTwo(4));
	EXPECT_TRUE(solution_.isPowerOfTwo(8));
	EXPECT_TRUE(solution_.isPowerOfTwo(16));
	EXPECT_TRUE(solution_.isPowerOfTwo(1024));
}

TEST_F(SolutionTest, case2) {
	EXPECT_FALSE(solution_.isPowerOfTwo(0));
	EXPECT_FALSE(solution_.isPowerOfTwo(3));
	EXPECT_FALSE(solution_.isPowerOfTwo(5));
	EXPECT_FALSE(solution_.isPowerOfTwo(9));
	EXPECT_FALSE(solution_.isPowerOfTwo(11));
}

