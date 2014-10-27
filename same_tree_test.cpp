/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/same-tree/
 * Problem:	Same Tree
 *               
 */
#include <gtest/gtest.h>
#include "same_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root1 = new TreeNode(0);
	TreeNode *root2 = new TreeNode(0);
	EXPECT_TRUE(solution_.isSameTree(root1, root2));
}

TEST_F(SolutionTest, case2) {
	TreeNode *root1 = new TreeNode(0);
	TreeNode *root2 = new TreeNode(1);
	EXPECT_FALSE(solution_.isSameTree(root1, root2));
}

