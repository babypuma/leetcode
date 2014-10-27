/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Problem:	Construct Binary Tree from Preorder and Inorder Traversal
 *               
 */
#include <gtest/gtest.h>
#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"

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
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	int pre[] = {1, 2, 4, 5, 3, 6, 7};
	int in[] = {4, 2, 5, 1, 6, 3, 7};
	vector<int> preorder(pre, pre + sizeof(pre)/sizeof(int));
	vector<int> inorder(in, in + sizeof(in)/sizeof(int));
	TreeNode *node = solution_.buildTree(preorder, inorder);
	EXPECT_TRUE(solution_.isSameTree(root, node));
}

TEST_F(SolutionTest, case2) {
	vector<int> preorder;
	vector<int> inorder;
	TreeNode *node = solution_.buildTree(preorder, inorder);
	EXPECT_TRUE(node == NULL);
}

