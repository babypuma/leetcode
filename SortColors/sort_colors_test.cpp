/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/18
 *
 * Source : https://leetcode.com/problems/sort-colors/
 * Problem:	Sort Colors
 *
 */
#include <gtest/gtest.h>
#include "sort_colors.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 2, 0, 2, 1, 0, 2, 0};
	int b[] = {0, 0, 0, 1, 1, 2, 2, 2};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	solution_.sortColors(vec);
	for (size_t i = 0; i < vec.size(); i++) {
		EXPECT_EQ(vec[i], b[i]);
	}
}

