/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
 * Problem:	Pascal's Triangle II
 *
 */
#include <gtest/gtest.h>
#include "pascals_riangle_ii.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int row_index = 9;
	vector<int> vec = solution_.getRow(row_index);

	int a[] = {1, 9, 36, 84, 126, 126, 84, 36, 9, 1};
	ASSERT_EQ(sizeof(a)/sizeof(int), vec.size());
	for (int i = 0; i < row_index; i++) {
		ASSERT_EQ(a[i], vec[i]);
	}
}

TEST_F(SolutionTest, case2) {
	int row_index = 0;
	vector<int> vec = solution_.getRow(row_index);
	ASSERT_EQ(1, (int)vec.size());
	EXPECT_EQ(1, vec[0]);
}

