/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 * Problem:	Binary Tree Level Order Traversal
 *               
 */
#include <gtest/gtest.h>
#include "binary_tree_level_order_traversal.h"

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
	vector<vector<int> > vec2d = solution_.levelOrder(root);
	EXPECT_EQ((int)vec2d.size(), 3);
	EXPECT_EQ((int)vec2d[0].size(), 1);
	EXPECT_EQ(vec2d[0][0], 3);
	EXPECT_EQ((int)vec2d[1].size(), 2);
	EXPECT_EQ(vec2d[1][0], 9);
	EXPECT_EQ(vec2d[1][1], 20);
	EXPECT_EQ((int)vec2d[2].size(), 2);
	EXPECT_EQ(vec2d[2][0], 15);
	EXPECT_EQ(vec2d[2][1], 7);
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = NULL;
	vector<vector<int> > vec2d = solution_.levelOrder(root);
	EXPECT_EQ((int)vec2d.size(), 0);
}

