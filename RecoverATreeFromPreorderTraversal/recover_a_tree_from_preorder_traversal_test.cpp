/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/25
 *
 * Source : https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
 * Problem: Recover a Tree From Preorder Traversal
 *               
 */
#include <gtest/gtest.h>
#include "recover_a_tree_from_preorder_traversal.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  TreeNode* root = solution_.recoverFromPreorder("1-2--3--4-5--6--7");
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left->val, 2);
  EXPECT_EQ(root->right->val, 5);
  EXPECT_EQ(root->left->val, 2);
  EXPECT_EQ(root->left->left->val, 3);
  EXPECT_EQ(root->left->right->val, 4);
  EXPECT_EQ(root->right->left->val, 6);
  EXPECT_EQ(root->right->right->val, 7);
}

