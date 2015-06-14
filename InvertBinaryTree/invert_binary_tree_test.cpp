/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/14
 *
 * Source : https://oj.leetcode.com/problems/invert-binary-tree/
 * Problem:	Invert Binary Tree
 *
 */
#include <gtest/gtest.h>
#include "invert_binary_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	root = solution_.invertTree(root);
	EXPECT_EQ(root->val, 4);
	EXPECT_EQ(root->left->val, 7);
	EXPECT_EQ(root->right->val, 2);
	EXPECT_EQ(root->left->left->val, 9);
	EXPECT_EQ(root->left->right->val, 6);
	EXPECT_EQ(root->right->left->val, 3);
	EXPECT_EQ(root->right->right->val, 1);
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root = solution_.invertTree(root);
	EXPECT_EQ(root->val, 1);
	EXPECT_TRUE(root->left == NULL);
	EXPECT_TRUE(root->right != NULL);
	EXPECT_EQ(root->right->val, 2);
}

