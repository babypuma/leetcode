/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/07
 *
 * Source : https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 * Problem:	Sum Root to Leaf Numbers
 *
 */
#include <gtest/gtest.h>
#include "sum_root_to_leaf_numbers.h"

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
	EXPECT_EQ(solution_.sumNumbers(root), 25);
}

