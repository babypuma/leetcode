/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/07
 *
 * Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Problem:	Unique Binary Search Trees II
 *
 */
/**
 * Definition for a binary tree node.
 */

#include <vector>
#include <iostream>
using std::vector;
using std::cout;

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
    vector<TreeNode*> generateTrees(int n) {
      if (n == 0) {
        return vector<TreeNode*>();
      }
      return generateTrees(1, n);
    }

private:
    vector<TreeNode*> generateTrees(int start, int end) {
      vector<TreeNode*> vec;
      if (start > end) {
        vec.push_back(nullptr);
        return vec;
      } else if (start == end) {
        vec.push_back(new TreeNode(start));
        return vec;
      }

      for (int i = start; i <= end; ++i) {
        vector<TreeNode*> left = generateTrees(start, i - 1);
        vector<TreeNode*> right = generateTrees(i + 1, end);
        for (size_t j = 0; j < left.size(); ++j) {
          for (size_t k = 0; k < right.size(); ++k) {
            vec.push_back(new TreeNode(i, left[j], right[k]));
          }
        }
      }
      return vec;
    }
};
