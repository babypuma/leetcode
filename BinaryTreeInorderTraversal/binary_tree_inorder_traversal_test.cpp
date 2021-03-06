/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 * Problem:	Binary Tree Inorder Traversal
 *
 */
#include <gtest/gtest.h>
#include "binary_tree_inorder_traversal.h"

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
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	vector<int> vec = solution_.inorderTraversal(root);
	ASSERT_EQ((int)vec.size(), 3);
	int a[] = {1, 3, 2};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		EXPECT_EQ(a[i], vec[i]);
	}
}

