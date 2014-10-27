/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/symmetric-tree/
 * Problem:	Symmetric Tree
 *               
 */
#include <gtest/gtest.h>
#include "symmetric_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(0);
	EXPECT_TRUE(solution_.isSymmetric(root));
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	EXPECT_TRUE(solution_.isSymmetric(root));
}

