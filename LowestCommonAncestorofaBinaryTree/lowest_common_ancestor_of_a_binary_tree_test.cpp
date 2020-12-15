/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/13
 * Update : 2020/12/15
 *
 * Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Problem:	Lowest Common Ancestor of a Binary Tree
 *
 */
#include <gtest/gtest.h>
#include "lowest_common_ancestor_of_a_binary_tree.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  TreeNode *node = solution_.lowestCommonAncestor(root, root->left, root->right);
  EXPECT_EQ(node->val, root->val);
}

TEST_F(SolutionTest, case2) {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  TreeNode *node = solution_.lowestCommonAncestor(root, root->left->left, root->left->right);
  EXPECT_EQ(node->val, root->left->val);
}

TEST_F(SolutionTest, case3) {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	TreeNode *node = solution_.lowestCommonAncestor(root, root->left, root->left->right->right);
	EXPECT_EQ(node->val, root->left->val);
}

