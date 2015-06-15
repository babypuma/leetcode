/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/15
 *
 * Source : https://oj.leetcode.com/problems/compare-version-numbers/
 * Problem:	Compare Version Numbers
 *
 */
#include <gtest/gtest.h>
#include "compare_version_numbers.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.compareVersion("0.1", "0.1"), 0);
	EXPECT_EQ(solution_.compareVersion("1.1", "1.1"), 0);
	EXPECT_EQ(solution_.compareVersion("1.2", "1.2"), 0);
	EXPECT_EQ(solution_.compareVersion("13.37", "13.37"), 0);

	EXPECT_EQ(solution_.compareVersion("0.1", "1.1"), -1);
	EXPECT_EQ(solution_.compareVersion("1.1", "0.1"), 1);
	EXPECT_EQ(solution_.compareVersion("1.1", "2.1"), -1);
	EXPECT_EQ(solution_.compareVersion("2.1", "1.1"), 1);
	EXPECT_EQ(solution_.compareVersion("1.2", "13.37"), -1);
	EXPECT_EQ(solution_.compareVersion("13.37", "1.2"), 1);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.compareVersion(".1", "0.1"), 0);
	EXPECT_EQ(solution_.compareVersion(".1", "0.2"), -1);
	EXPECT_EQ(solution_.compareVersion("1.", "1.0"), 0);
	EXPECT_EQ(solution_.compareVersion("1.", "1.1"), -1);
	EXPECT_EQ(solution_.compareVersion("1.1", "1.1.1"), -1);
}

TEST_F(SolutionTest, case3) {
	EXPECT_EQ(solution_.compareVersion("1.0", "1"), 0);
}

TEST_F(SolutionTest, case4) {
	vector<int> vec;
	vec = solution_.split("1.0");
	EXPECT_EQ(vec.size(), 2);
	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 0);
	vec = solution_.split("1.");
	EXPECT_EQ(vec.size(), 2);
	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 0);
	vec = solution_.split(".1");
	EXPECT_EQ(vec.size(), 2);
	EXPECT_EQ(vec[0], 0);
	EXPECT_EQ(vec[1], 1);
}

