/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/07
 *
 * Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Problem:	Convert Sorted Array to Binary Search Tree
 *
 */
#include <gtest/gtest.h>
#include "convert_sorted_array_to_binary_search_tree.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, generateTrees) {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);

	TreeNode* node = solution_.sortedArrayToBST(nums);
  EXPECT_EQ(node->val, 2);
  EXPECT_TRUE(node->left != nullptr);
  EXPECT_TRUE(node->right != nullptr);
  EXPECT_EQ(node->left->val, 1);
  EXPECT_EQ(node->right->val, 3);
}
