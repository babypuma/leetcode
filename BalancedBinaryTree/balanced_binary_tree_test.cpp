/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/balanced-binary-tree/
 * Problem:	Balanced Binary Tree
 *
 */
#include <gtest/gtest.h>
#include "balanced_binary_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	EXPECT_FALSE(solution_.isBalanced(root));
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	EXPECT_TRUE(solution_.isBalanced(root));
}

