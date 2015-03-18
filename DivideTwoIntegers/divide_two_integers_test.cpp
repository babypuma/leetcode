/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/divide-two-integers/
 * Problem:	Divide Two Integers 
 *               
 */
#include <gtest/gtest.h>
#include "divide_two_integers.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};


TEST_F(SolutionTest, case1) {
	//EXPECT_EQ(Solution::MY_INT32_MAX, 2147483647);
	//EXPECT_EQ(Solution::MY_INT32_MIN, -2147483648);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.divide(10, 1), 10);
}

TEST_F(SolutionTest, case3) {
	EXPECT_EQ(solution_.divide(10, -1), -10);
}

TEST_F(SolutionTest, case4) {
	EXPECT_EQ(solution_.divide(-10, -1), 10);
}

TEST_F(SolutionTest, case5) {
	EXPECT_EQ(solution_.divide(-10, 3), -3);
}

TEST_F(SolutionTest, case6) {
	EXPECT_EQ(solution_.divide(2, 3), 0);
}

TEST_F(SolutionTest, case7) {
	EXPECT_EQ(solution_.divide(2147483647, 1), 2147483647);
}

TEST_F(SolutionTest, case8) {
	EXPECT_EQ(solution_.divide(-1010369383, -2147483648), 0);
}

TEST_F(SolutionTest, case9) {
	EXPECT_EQ(solution_.divide(1100540749, -1090366779), -1);
}

TEST_F(SolutionTest, case10) {
	EXPECT_EQ(solution_.divide(2147483647, -2147483648), 0);
}

