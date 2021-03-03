/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 * Update : 2021/03/03
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 * Problem:	Binary Tree Postorder Traversal
 *
 */
#include <stdio.h>
#include <stack>
#include <vector>
using std::stack;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum status {
  st_unknown,
  st_left,
  st_right,
};

struct ExTreeNode {
  TreeNode *tn;
  status st;
  ExTreeNode() : tn(nullptr), st(st_unknown) {}
  ExTreeNode(TreeNode *n) : tn(n), st(st_left) {}
};

class Solution {
 public:
   vector<int> postorderTraversal(TreeNode *root) {
     vector<int> vec;
     stack<ExTreeNode> st; 
     while (root != nullptr || !st.empty()) {
       if (root != nullptr) {
         st.push(ExTreeNode(root));
         root = root->left;
       } else {
         ExTreeNode node = st.top();
         st.pop();
         if (node.st == st_left) {
           node.st = st_right;
           st.push(node);
           root = node.tn->right;
         } else {
           vec.push_back(node.tn->val);
         }
       }
     }
     return vec;
   }
};
