/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/29
 *
 * Source : https://leetcode.com/problems/summary-ranges/
 * Problem:	Summary Ranges
 * Description: 
 *	Given a sorted integer array without duplicates, return the summary of its ranges.
 * 	For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 */
#include <gtest/gtest.h>
#include "summary_ranges.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {0, 1, 2, 4, 5, 7};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	vector<string> v = solution_.summaryRanges(vec);
	EXPECT_EQ(v.size(), 3);
	EXPECT_STREQ(v[0].c_str(), "0->2");
	EXPECT_STREQ(v[1].c_str(), "4->5");
	EXPECT_STREQ(v[2].c_str(), "7");
}

TEST_F(SolutionTest, case2) {
	string str;
	str = solution_.itos(0);
	EXPECT_STREQ(str.c_str(), "0");
	str = solution_.itos(-12);
	EXPECT_STREQ(str.c_str(), "-12");
	str = solution_.itos(12);
	EXPECT_STREQ(str.c_str(), "12");
}

TEST_F(SolutionTest, case3) {
	int a[] = {-2147483648, -2147483647, 2147483647};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	vector<string> v = solution_.summaryRanges(vec);
	EXPECT_EQ(v.size(), 2);
	EXPECT_STREQ(v[0].c_str(), "-2147483648->-2147483647");
	EXPECT_STREQ(v[1].c_str(), "2147483647");
}

TEST_F(SolutionTest, case4) {
	int a[] = {1, 3};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	vector<string> v = solution_.summaryRanges(vec);
	EXPECT_EQ(v.size(), 2);
	EXPECT_STREQ(v[0].c_str(), "1");
	EXPECT_STREQ(v[1].c_str(), "3");
}

