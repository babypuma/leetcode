/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 * Problem:	Find Mode in Binary Search Tree
 *               
 */
#include <gtest/gtest.h>
#include "find_mode_in_binary_search_tree.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
}

TEST_F(SolutionTest, case2) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(2);
  vector<int> mode = solution_.findMode(root);
  EXPECT_EQ(mode.size(), 1);
  EXPECT_EQ(mode[0], 2);
}

