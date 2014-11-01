/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/unique-binary-search-trees/
 * Problem:	Unique Binary Search Trees
 *
 */
#include <gtest/gtest.h>
#include "unique_binary_search_trees.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.numTrees(3), 5);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.numTrees(4), 14);
}

