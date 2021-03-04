/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/03
 *
 * Source : https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 * Problem: N-ary Tree Postorder Traversal
 *               
 */
#include <gtest/gtest.h>
#include "nary_tree_postorder_traversal.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  Node* root = new Node(1);
  Node* child = new Node(3);
  child->children.push_back(new Node(5));
  child->children.push_back(new Node(6));
  root->children.push_back(child);
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(4));
  vector<int> v = solution_.postorder(root);
  int a[] = {5,6,3,2,4,1};
  EXPECT_EQ(v.size(), sizeof(a)/sizeof(a[0]));
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    EXPECT_EQ(v[i], a[i]);
  }
}

