/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/08
 *
 * Source : https://leetcode-cn.com/contest/weekly-contest-292/problems/count-nodes-equal-to-average-of-subtree/
 * Problem: Count Nodes Equal to Average of Subtree
 *
 */
#include <gtest/gtest.h>
#include "count_nodes_equal_to_average_of_subtree.h"

TEST(Solution, case1) {
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
  Solution s;
  EXPECT_EQ(s.averageOfSubtree(root), 5);
}

