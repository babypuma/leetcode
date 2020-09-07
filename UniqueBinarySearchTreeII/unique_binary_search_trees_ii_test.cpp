/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/07
 *
 * Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Problem:	Unique Binary Search Trees II
 *
 */
#include <gtest/gtest.h>
#include "unique_binary_search_trees_ii.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, generateTrees) {
	vector<TreeNode*> vec = solution_.generateTrees(3);
	EXPECT_EQ(vec.size(), 5);
}
