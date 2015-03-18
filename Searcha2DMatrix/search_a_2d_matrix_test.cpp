/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/search-a-2d-matrix/
 * Problem:	Search a 2D Matrix
 *
 */
#include <gtest/gtest.h>
#include <set>
#include "search_a_2d_matrix.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<vector<int> > vec2d;
	int a[][4] = {{1,   3,  5,  7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	EXPECT_TRUE(solution_.searchMatrix(vec2d, 3));
	EXPECT_TRUE(solution_.searchMatrix(vec2d, 23));
	EXPECT_FALSE(solution_.searchMatrix(vec2d, 0));
	EXPECT_FALSE(solution_.searchMatrix(vec2d, 12));
}

TEST_F(SolutionTest, case2) {
	vector<vector<int> > vec2d;
	int a[][2] = {{1, 1}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[2]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	EXPECT_TRUE(solution_.searchMatrix(vec2d, 1));
	EXPECT_FALSE(solution_.searchMatrix(vec2d, 2));
}

