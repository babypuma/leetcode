/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 * Problem:	Minimum Depth of Binary Tree
 *
 */
#include <gtest/gtest.h>
#include "minimum_depth_of_binary_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	EXPECT_EQ(solution_.minDepth(root), 2);
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = NULL;
	EXPECT_EQ(solution_.minDepth(root), 0);
}

TEST_F(SolutionTest, case3) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	EXPECT_EQ(solution_.minDepth(root), 2);
}

TEST_F(SolutionTest, case4) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(3);
	root->left->right->left = new TreeNode(4);
	root->left->right->left->right = new TreeNode(5);
	EXPECT_EQ(solution_.minDepth(root), 5);
}

