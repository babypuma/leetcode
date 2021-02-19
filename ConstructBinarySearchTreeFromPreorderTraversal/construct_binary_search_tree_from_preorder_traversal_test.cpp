/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/19
 *
 * Source : https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * Problem: Construct Binary Search Tree from Preorder Traversal
 *               
 */
#include <gtest/gtest.h>
#include "construct_binary_search_tree_from_preorder_traversal.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {8,5,1,7,10,12};
  vector<int> preorder(a, a + sizeof(a) / sizeof(a[0]));
  TreeNode* root = solution_.bstFromPreorder(preorder);
  ASSERT_TRUE(root != nullptr);
  EXPECT_EQ(root->val, 8);
  EXPECT_EQ(root->left->val, 5);
  EXPECT_EQ(root->left->left->val, 1);
  EXPECT_EQ(root->left->right->val, 7);
  EXPECT_EQ(root->right->val, 10);
  EXPECT_EQ(root->right->right->val, 12);
}

