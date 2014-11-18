/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/19
 *
 * Source : https://oj.leetcode.com/problems/search-for-a-range/
 * Problem:	Search for a Range
 *
 */
#include <gtest/gtest.h>
#include "search_for_a_range.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {5, 7, 7, 8, 8, 10};
	vector<int> vec = solution_.searchRange(a, (int)sizeof(a)/sizeof(int), 8);
	EXPECT_EQ(vec[0], 3);
	EXPECT_EQ(vec[1], 4);
}

TEST_F(SolutionTest, case2) {
	int a[] = {5, 7, 7, 8, 8, 10};
	vector<int> vec = solution_.searchRange(a, (int)sizeof(a)/sizeof(int), 5);
	EXPECT_EQ(vec[0], 0);
	EXPECT_EQ(vec[1], 0);
}

TEST_F(SolutionTest, case3) {
	int a[] = {5, 7, 7, 8, 8, 10};
	vector<int> vec = solution_.searchRange(a, (int)sizeof(a)/sizeof(int), 9);
	EXPECT_EQ(vec[0], -1);
	EXPECT_EQ(vec[1], -1);
}

