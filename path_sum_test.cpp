/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/14
 *
 * Source : https://oj.leetcode.com/problems/path-sum/
 * Problem:	Path Sum
 *
 */
#include <gtest/gtest.h>
#include "path_sum.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	EXPECT_TRUE(solution_.hasPathSum(root, 22));
}

