/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 * Update : 2021/03/03
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 * Problem:	Binary Tree Inorder Traversal
 *
 */
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

class Solution {
 public:
   vector<int> inorderTraversal(TreeNode *root) {
     vector<int> vec;
     stack<TreeNode *> st;
     while (root != nullptr || !st.empty()) {
       if (root != nullptr) {
         st.push(root);
         root = root->left;
       } else {
         root = st.top();
         st.pop();
         vec.push_back(root->val);
         root = root->right;
       }
     }

     return vec;
   }
};
