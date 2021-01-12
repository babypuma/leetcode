/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/12
 *
 * Source : https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 * Problem: Serialize and Deserialize Binary Tree
 *               
 */
#include <gtest/gtest.h>
#include "serialize_and_deserialize_binary_tree.h"

TEST(SolutionTest, serialize) {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Codec codec;
  string str = codec.serialize(root);
  EXPECT_STREQ(str.c_str(), "(X)1(((X)3(X))2(X))");
}

TEST(SolutionTest, deserialize) {
  Codec codec;
  string str = "(X)1(((X)3(X))2(X))";
  TreeNode* node = codec.deserialize(str);
  EXPECT_TRUE(node != NULL);
  EXPECT_EQ(node->val, 1);
  EXPECT_TRUE(node->left == NULL);
  EXPECT_TRUE(node->right != NULL);
  EXPECT_EQ(node->right->val, 2);
  EXPECT_TRUE(node->right->left != NULL);
  EXPECT_TRUE(node->right->right == NULL);
  EXPECT_EQ(node->right->left->val, 3);
}

