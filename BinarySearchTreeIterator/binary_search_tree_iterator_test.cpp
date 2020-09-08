/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 *
 * Source : https://leetcode.com/problems/binary-search-tree-iterator/
 * Problem:	Binary Search Tree Iterator
 *
 */
#include <gtest/gtest.h>
#include "binary_search_tree_iterator.h"

TEST(SolutionTest, BSTIterator) {
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
  BSTIterator it(root);
	EXPECT_TRUE(it.hasNext());
  EXPECT_EQ(it.next(), 1);
  EXPECT_EQ(it.next(), 3);
	EXPECT_TRUE(it.hasNext());
  EXPECT_EQ(it.next(), 2);
	EXPECT_TRUE(!it.hasNext());
}

