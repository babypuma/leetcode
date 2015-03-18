/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/spiral-matrix-ii/
 * Problem:	Spiral Matrix II
 *
 */
#include <gtest/gtest.h>
#include <set>
#include "spiral_matrix_ii.h"

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
	int a[][1] = {{1}};
	vec2d = solution_.generateMatrix(1);
	ASSERT_EQ(sizeof(a)/sizeof(int[1]), vec2d.size());
	for (size_t i = 0; i < sizeof(a)/sizeof(int[1]); i++) {
		for (size_t j = 0; j < sizeof(a[i])/sizeof(int); j++) {
			EXPECT_EQ(vec2d[i][j], a[i][j]);
		}
	}
}

TEST_F(SolutionTest, case2) {
	vector<vector<int> > vec2d;
	int a[][2] = {{1, 2}, {4, 3}};
	vec2d = solution_.generateMatrix(2);
	ASSERT_EQ(sizeof(a)/sizeof(int[2]), vec2d.size());
	for (size_t i = 0; i < sizeof(a)/sizeof(int[2]); i++) {
		for (size_t j = 0; j < sizeof(a[i])/sizeof(int); j++) {
			EXPECT_EQ(vec2d[i][j], a[i][j]);
		}
	}
}

TEST_F(SolutionTest, case3) {
	vector<vector<int> > vec2d;
	int a[][3] = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
	vec2d = solution_.generateMatrix(3);
	ASSERT_EQ(sizeof(a)/sizeof(int[3]), vec2d.size());
	for (size_t i = 0; i < sizeof(a)/sizeof(int[3]); i++) {
		for (size_t j = 0; j < sizeof(a[i])/sizeof(int); j++) {
			EXPECT_EQ(vec2d[i][j], a[i][j]);
		}
	}
}

TEST_F(SolutionTest, case4) {
	vector<vector<int> > vec2d;
	int a[][4] = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	ASSERT_EQ(sizeof(a)/sizeof(int[4]), vec2d.size());
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		for (size_t j = 0; j < sizeof(a[i])/sizeof(int); j++) {
			EXPECT_EQ(vec2d[i][j], a[i][j]);
		}
	}
}

