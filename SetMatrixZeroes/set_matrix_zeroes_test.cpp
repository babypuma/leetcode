/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/set-matrix-zeroes/
 * Problem:	Set Matrix Zeroes
 *
 */
#include <gtest/gtest.h>
#include <set>
#include "set_matrix_zeroes.h"

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
	int a[][4] = {{1,  0,  5,  7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}

	int b[][4] = {{0,  0,  0,  0}, {10, 0, 16, 20}, {23, 0, 34, 50}};
	solution_.setZeroes(vec2d);
	for (size_t i = 0; i < sizeof(b)/sizeof(int[4]); i++) {
		for (size_t j = 0; j < sizeof(b[i])/sizeof(int); j++) {
			EXPECT_EQ(b[i][j], vec2d[i][j]);
		}
	}
}

