/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
 * Problem: LowestCommonAncestorOfABinaryTreeIV
 *               
 */
#include <gtest/gtest.h>
#include "lowest_common_ancestor_of_a_binary_tree_iv.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  vector<TreeNode*> nodes;
  nodes.push_back(root->left->left);
  nodes.push_back(root->left->right);
  nodes.push_back(root->left->right->left);
  nodes.push_back(root->left->right->right);
  TreeNode* n = solution_.lowestCommonAncestor(root, nodes);
  EXPECT_TRUE(n != nullptr);
  EXPECT_EQ(n->val, 5);
}

