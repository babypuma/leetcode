/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/search-insert-position/
 * Problem:	Search Insert Position
 *
 */
#include <gtest/gtest.h>
#include "search_insert_position.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 3, 5, 6};
	EXPECT_EQ(solution_.searchInsert(a, (int)sizeof(a)/sizeof(int), 5), 2);
}

TEST_F(SolutionTest, case2) {
	int a[] = {1, 3, 5, 6};
	EXPECT_EQ(solution_.searchInsert(a, (int)sizeof(a)/sizeof(int), 2), 1);
}

TEST_F(SolutionTest, case3) {
	int a[] = {1, 3, 5, 6};
	EXPECT_EQ(solution_.searchInsert(a, (int)sizeof(a)/sizeof(int), 7), 4);
}

TEST_F(SolutionTest, case4) {
	int a[] = {1, 3, 5, 6};
	EXPECT_EQ(solution_.searchInsert(a, (int)sizeof(a)/sizeof(int), 0), 0);
}

