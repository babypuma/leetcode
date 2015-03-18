/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/23
 *
 * Source :	https://oj.leetcode.com/problems/combinations/
 * Problem:	Combinations
 *
 */
#include <gtest/gtest.h>
#include "combinations.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<vector<int> > vec2d = solution_.combine(10, 1);
	EXPECT_EQ((int)vec2d.size(), 10);
	for (size_t i = 0; i < vec2d.size(); i++) {
		EXPECT_EQ((int)vec2d[i].size(), 1);
	}
}

TEST_F(SolutionTest, case2) {
	vector<vector<int> > vec2d = solution_.combine(10, 2);
	EXPECT_EQ((int)vec2d.size(), 45);
	for (size_t i = 0; i < vec2d.size(); i++) {
		EXPECT_EQ((int)vec2d[i].size(), 2);
	}
}

TEST_F(SolutionTest, case3) {
	vector<vector<int> > vec2d = solution_.combine(10, 5);
	EXPECT_EQ((int)vec2d.size(), 252);
	for (size_t i = 0; i < vec2d.size(); i++) {
		EXPECT_EQ((int)vec2d[i].size(), 5);
	}
}

TEST_F(SolutionTest, case4) {
	vector<vector<int> > vec2d = solution_.combine(1, 1);
	EXPECT_EQ((int)vec2d.size(), 1);
	for (size_t i = 0; i < vec2d.size(); i++) {
		EXPECT_EQ((int)vec2d[i].size(), 1);
	}
}

