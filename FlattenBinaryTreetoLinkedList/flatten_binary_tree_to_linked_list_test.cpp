/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/15
 *
 * Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Problem:	Flatten Binary Tree to Linked List
 *
 */
#include <gtest/gtest.h>
#include "flatten_binary_tree_to_linked_list.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);

	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	TreeNode *node = root;
	solution_.flatten(root);
	int a[] = {1, 2, 3, 4, 5, 6};
	size_t i = 0;
	for (; i < sizeof(a)/sizeof(int); i++) {
		ASSERT_TRUE(node != NULL);
		EXPECT_EQ(node->val, a[i]);
		EXPECT_TRUE(node->left == NULL);
		node = node->right;
	}
	EXPECT_EQ(sizeof(a)/sizeof(int), i);
}

