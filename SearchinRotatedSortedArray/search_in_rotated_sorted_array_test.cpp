/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 * Problem:	Search in Rotated Sorted Array 
 *
 */
#include <gtest/gtest.h>
#include "search_in_a_rotated_array.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 4), 0);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 2), 6);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 7), 3);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 0), 4);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 8), -1);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), -1), -1);
}

TEST_F(SolutionTest, case2) {
	int a[] = {1, 3};
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 3), 1);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 1), 0);
	EXPECT_EQ(solution_.search(a, (int)sizeof(a)/sizeof(int), 2), -1);
}

