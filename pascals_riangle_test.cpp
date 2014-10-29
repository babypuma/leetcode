/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/pascals-triangle/
 * Problem:	Pascal's Triangle
 *
 */
#include <gtest/gtest.h>
#include "pascals_riangle.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	size_t vec_size = 10;
	vector<vector<int> > vec2d = solution_.generate(vec_size);
	EXPECT_EQ(vec_size, vec2d.size());
	for (size_t i = 0; i < vec_size; i++) {
		ASSERT_EQ(i+1, vec2d[i].size());
		for (size_t j = 0; j < i+1; j++) {
			printf("%d\t", vec2d[i][j]);
		}
		printf("\n");
	}
}

TEST_F(SolutionTest, case2) {
	vector<vector<int> > vec2d = solution_.generate(0);
	EXPECT_EQ(0, (int)vec2d.size());
}

