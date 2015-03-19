/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 * Problem:	Maximum Depth of Binary Tree
 *               
 */
#include <gtest/gtest.h>
#include "maximum_depth_of_binary_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	EXPECT_EQ(solution_.maxDepth(root), 3);
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = NULL;
	EXPECT_EQ(solution_.maxDepth(root), 0);
}

