/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 *
 * Source : https://leetcode.com/problems/sum-of-left-leaves/
 * Problem:	Sum of Left Leaves
 *
 */
#include <gtest/gtest.h>
#include "sum_of_left_leaves.h"

TEST(SolutionTest, sumOfLeftLeaves) {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
  
  Solution solution;
  EXPECT_EQ(solution.sumOfLeftLeaves(root), 24);
}

