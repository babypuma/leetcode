/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/construct-binary-tree-from-postorder-and-postorder-traversal/
 * Problem:	Construct Binary Tree from Inorder and Postorder Traversal 
 *               
 */
#include <gtest/gtest.h>
#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"

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

	int in[] = {4, 2, 5, 1, 6, 3, 7};
	int post[] = {4, 5, 2, 6, 7, 3, 1};
	vector<int> inorder(in, in + sizeof(in)/sizeof(int));
	vector<int> postorder(post, post + sizeof(post)/sizeof(int));
	TreeNode *node = solution_.buildTree(inorder, postorder);
	EXPECT_TRUE(solution_.isSameTree(root, node));
}

TEST_F(SolutionTest, case2) {
	vector<int> inorder;
	vector<int> postorder;
	TreeNode *node = solution_.buildTree(inorder, postorder);
	EXPECT_TRUE(node == NULL);
}

