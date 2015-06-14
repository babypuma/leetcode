/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 * Problem:	Binary Tree Preorder Traversal
 *
 */
#include <gtest/gtest.h>
#include "binary_tree_preorder_traversal.h"

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
	vector<int> vec = solution_.preorderTraversal(root);
	ASSERT_EQ((int)vec.size(), 3);
	int a[] = {1, 2, 3};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		EXPECT_EQ(a[i], vec[i]);
	}
}

TEST_F(SolutionTest, case2) {
	TreeNode *root = NULL;
	vector<int> vec = solution_.preorderTraversal(root);
	ASSERT_TRUE(vec.empty());
}

TEST_F(SolutionTest, case3) {
	TreeNode *root = new TreeNode(1);
	vector<int> vec = solution_.preorderTraversal(root);
	ASSERT_TRUE(vec.size() == 1);
	ASSERT_TRUE(vec[0] == 1);
}

