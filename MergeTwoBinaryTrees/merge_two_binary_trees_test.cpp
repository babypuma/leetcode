/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/06/01
 *
 * Source : https://leetcode.cn/problems/merge-two-binary-trees/
 * Problem: Merge Two Binary Trees
 *
 */
#include <gtest/gtest.h>
#include "merge_two_binary_trees.h"

TEST(Solution, testcase) {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(3);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(5);

  TreeNode *root2 = new TreeNode(2);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(3);
  root2->left->right = new TreeNode(4);
  root2->right->right = new TreeNode(7);

  Solution solution;
  TreeNode *root = solution.mergeTrees(root1, root2);
  EXPECT_EQ(root->val, 3);
  EXPECT_EQ(root->left->val, 4);
  EXPECT_EQ(root->right->val, 5);
  EXPECT_EQ(root->left->left->val, 5);
  EXPECT_EQ(root->left->right->val, 4);
  EXPECT_EQ(root->right->right->val, 7);
}

