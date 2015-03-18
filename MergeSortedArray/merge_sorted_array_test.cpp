/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/merge-sorted-array/
 * Problem:	Merge Sorted Array
 *
 */
#include <gtest/gtest.h>
#include "merge_sorted_array.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[8] = {1, 3, 5, 7};
	int b[] = {2, 4, 6, 8};
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
	solution_.merge(a, 4, b, 4);
	for (size_t i = 0; i < sizeof(c)/sizeof(int); i++) {
		EXPECT_EQ(c[i], a[i]);
	}
}

