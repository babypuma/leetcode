/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2020/09/27
 *
 * Source : https://leetcode-cn.com/problems/house-robber/
 * Problem:	House Robber
 *
 */
#include <gtest/gtest.h>
#include "house_robber.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 8, 6, 9, 7, 2, 4, 9};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	EXPECT_EQ(solution_.rob(vec), 28);
}

TEST_F(SolutionTest, case2) {
	int a[] = {1, 8, 6};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	EXPECT_EQ(solution_.rob(vec), 8);
}

TEST_F(SolutionTest, case3) {
	int a[] = {1, 2};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	EXPECT_EQ(solution_.rob(vec), 2);
}

TEST_F(SolutionTest, case4) {
	int a[] = {2, 1, 1, 2};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	EXPECT_EQ(solution_.rob(vec), 4);
}

TEST_F(SolutionTest, case5) {
	int a[] = {2, 1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	EXPECT_EQ(solution_.rob(vec), 2);
}
