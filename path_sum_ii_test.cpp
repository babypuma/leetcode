/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/14
 *
 * Source : https://oj.leetcode.com/problems/path-sum-ii/
 * Problem:	Path Sum II
 *
 */
#include <gtest/gtest.h>
#include "path_sum_ii.h"

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
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	vector<vector<int> > vec2d = solution_.pathSum(root, 22);
	EXPECT_EQ(2, (int)vec2d.size());
	int a[][4] = {{5, 4, 11, 2}, {5, 8, 4, 5}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		ASSERT_EQ(sizeof(a[i])/sizeof(int), vec2d[i].size());
		for (size_t j = 0; j < sizeof(a[i])/sizeof(int); j++) {
			EXPECT_EQ(a[i][j], vec2d[i][j]);
		}
	}
}

