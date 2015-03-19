/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Problem:	Populating Next Right Pointers in Each Node
 *
 */
#include <gtest/gtest.h>
#include "populating_next_right_pointers_in_each_node.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);
	solution_.connect(root);
	EXPECT_TRUE(root->next == NULL);

	EXPECT_TRUE(root->left->next == root->right);
	EXPECT_TRUE(root->right->next == NULL);

	EXPECT_TRUE(root->left->left->next == root->left->right);
	EXPECT_TRUE(root->left->right->next == root->right->left);
	EXPECT_TRUE(root->right->left->next == root->right->right);
	EXPECT_TRUE(root->right->right->next == NULL);
}

