/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/07
 *
 * Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Problem:	Convert Sorted Array to Binary Search Tree
 *
 */

#include <vector>
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return generateTrees(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* generateTrees(vector<int>& nums, int begin, int end) {
      if (begin > end) {
        return nullptr;
      } else if (begin == end) {
        return new TreeNode(nums[begin]);
      }

      int mid = (end + begin) / 2;
      TreeNode* left = generateTrees(nums, begin, mid - 1);
      TreeNode* right = generateTrees(nums, mid + 1, end);
      return new TreeNode(nums[mid], left, right);
    }
};
