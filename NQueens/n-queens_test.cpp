/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/21
 *
 * Source : https://oj.leetcode.com/problems/n-queens/
 * Problem:	N-Queens
 *
 */
#include <gtest/gtest.h>
#include "n-queens.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<vector<string> > v2d = solution_.solveNQueens(1);
	EXPECT_EQ((int)v2d.size(), 1);
	EXPECT_STREQ(v2d[0][0].c_str(), "Q");
}

TEST_F(SolutionTest, case2) {
	vector<vector<string> > v2d = solution_.solveNQueens(2);
	EXPECT_EQ((int)v2d.size(), 0);
}

TEST_F(SolutionTest, case3) {
	vector<vector<string> > v2d = solution_.solveNQueens(3);
	EXPECT_EQ((int)v2d.size(), 0);
}

TEST_F(SolutionTest, case4) {
	vector<vector<string> > v2d = solution_.solveNQueens(4);
	EXPECT_EQ((int)v2d.size(), 2);
}

