/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/21
 *
 * Source : https://oj.leetcode.com/problems/n-queens-ii/
 * Problem:	N-Queens II
 *
 */
#include <gtest/gtest.h>
#include "n-queens_ii.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.totalNQueens(1), 1);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.totalNQueens(2), 0);
}

TEST_F(SolutionTest, case3) {
	EXPECT_EQ(solution_.totalNQueens(3), 0);
}

TEST_F(SolutionTest, case4) {
	EXPECT_EQ(solution_.totalNQueens(4), 2);
}

