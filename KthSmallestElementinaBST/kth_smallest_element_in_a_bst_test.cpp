/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/13
 *
 * Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Problem:	Kth Smallest Element in a BST
 *
 */
#include <gtest/gtest.h>
#include "kth_smallest_element_in_a_bst.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	EXPECT_EQ(solution_.kthSmallest(root, 5), 5);
}

