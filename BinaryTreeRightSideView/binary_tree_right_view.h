/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 *
 * Source : https://leetcode.com/problems/binary-tree-right-side-view/
 * Problem:	Binary Tree Right Side View
 *
 */
#include <queue>
#include <vector>
#include <cmath>
using std::queue;
using std::vector;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct NodeWrapper {
  TreeNode *node;
  int idx;
  int level;
  NodeWrapper(TreeNode *n, int i, int l) : node(n), idx(i), level(l) {}
};

class Solution {
 public:
   vector<int> rightSideView(TreeNode* root) {
     levelOrderTraversal(root);
     return vec_;
   }

 private:
   void levelOrderTraversal(TreeNode* root) {
     if (root == nullptr) {
       return;
     }
     queue<NodeWrapper> que;
     que.push(NodeWrapper(root, 0, 0));
     while (!que.empty()) {
       NodeWrapper curr = que.front();
       que.pop();
       if (!que.empty()) {
         NodeWrapper next = que.front();
         if (curr.level < next.level) {
           vec_.push_back(curr.node->val);
         }
       } else {
         vec_.push_back(curr.node->val);
       }

       if (curr.node->left != nullptr) {
         int idx = 2 * curr.idx + 1;
         que.push(NodeWrapper(curr.node->left, idx, getLevel(idx)));
       }
       if (curr.node->right != nullptr) {
         int idx = 2 * curr.idx + 2;
         que.push(NodeWrapper(curr.node->right, idx, getLevel(idx)));
       }
     }
   }

   int getLevel(int idx) {
     return floor(log2(idx + 1));
   }

 private:
   vector<int> vec_;
};
