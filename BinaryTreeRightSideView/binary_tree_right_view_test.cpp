/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 *
 * Source : https://leetcode.com/problems/binary-tree-right-side-view/
 * Problem:	Binary Tree Right Side View
 *
 */
#include <gtest/gtest.h>
#include "binary_tree_right_view.h"

TEST(SolutionTest, rightSideView) {
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
  
  Solution solution;
  vector<int> vec = solution.rightSideView(root);
  EXPECT_EQ(vec.size(), 3);
}

