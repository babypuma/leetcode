/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 *
 * Source : https://leetcode.com/problems/sum-of-left-leaves/
 * Problem:	Sum of Left Leaves
 *
 */

/**
 * Definition for a binary tree node.
 */
#include <queue>
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeNodeWrapper {
  TreeNode *node;
  bool isLeft;
  TreeNodeWrapper(TreeNode *n, bool left) : node(n), isLeft(left) {}
};

class Solution {
 public:
   int sumOfLeftLeaves(TreeNode* root) {
     int sum = 0;
     levelOrderTraversal(root, sum);
     return sum;
   }

 private:
   void levelOrderTraversal(TreeNode* root, int& sum) {
     if (root == nullptr) {
       return;
     }
     queue<TreeNodeWrapper> que;
     que.push(TreeNodeWrapper(root, false));
     while (!que.empty()) {
       TreeNodeWrapper wrapper = que.front();
       que.pop();
       if (wrapper.node->left == nullptr && wrapper.node->right == nullptr && wrapper.isLeft) {
         sum += wrapper.node->val;
       }
       if (wrapper.node->left != nullptr) {
         que.push(TreeNodeWrapper(wrapper.node->left, true));
       }
       if (wrapper.node->right != nullptr) {
         que.push(TreeNodeWrapper(wrapper.node->right, false));
       }
     }
   }
};
