/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Problem:	Find Minimum in Rotated Sorted Array 
 *
 */
#include <gtest/gtest.h>
#include "find_minmum_in_rotated_sorted_array.h"

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
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.findMin(vec), 0);
}

TEST_F(SolutionTest, case2) {
	int a[] = {2, 1};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.findMin(vec), 1);
}

TEST_F(SolutionTest, case3) {
	int a[] = {1};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.findMin(vec), 1);
}

TEST_F(SolutionTest, case4) {
	int a[] = {3, 1, 2};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.findMin(vec), 1);
}

TEST_F(SolutionTest, case5) {
	int a[] = {1, 2};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.findMin(vec), 1);
}

