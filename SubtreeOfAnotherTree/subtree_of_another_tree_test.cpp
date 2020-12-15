/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/subtree-of-another-tree/
 * Problem: Subtree of Another Tree
 *               
 */
#include <gtest/gtest.h>
#include "subtree_of_another_tree.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  TreeNode* root1 = new TreeNode(3);
  root1->left = new TreeNode(4);
  root1->right = new TreeNode(5);
  root1->left->left = new TreeNode(1);
  root1->left->right = new TreeNode(2);

  TreeNode* root2 = new TreeNode(4);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(2);
  EXPECT_TRUE(solution_.isSubtree(root1, root2));
}

TEST_F(SolutionTest, case2) {
  TreeNode* root1 = new TreeNode(3);
  root1->left = new TreeNode(4);
  root1->right = new TreeNode(5);
  root1->left->left = new TreeNode(1);
  root1->left->right = new TreeNode(2);
  root1->left->right->left = new TreeNode(0);

  TreeNode* root2 = new TreeNode(4);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(2);
  EXPECT_FALSE(solution_.isSubtree(root1, root2));
}

