/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/05
 * Update : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/validate-binary-search-tree/
 * Problem:	Validate Binary Search Tree
 *
 */
#include <gtest/gtest.h>
#include "validate_binary_search_tree.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(5);
  root->right->left = new TreeNode(3);
  root->right->left->right = new TreeNode(4);
  EXPECT_TRUE(solution_.isValidBST(root));
}

TEST_F(SolutionTest, case2) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(6);
  EXPECT_FALSE(solution_.isValidBST(root));
}
