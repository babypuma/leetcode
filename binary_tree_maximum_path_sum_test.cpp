/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 * Problem:	Binary Tree Maximum Path Sum
 *
 */
#include <gtest/gtest.h>
#include "binary_tree_maximum_path_sum.h"

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
	EXPECT_EQ(solution_.maxPathSum(root), 6);
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = new TreeNode(2);
	root->right = new TreeNode(-1);
	EXPECT_EQ(solution_.maxPathSum(root), 2);
}

TEST_F(SolutionTest, case3) {
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	EXPECT_EQ(solution_.maxPathSum(root), 48);
}

