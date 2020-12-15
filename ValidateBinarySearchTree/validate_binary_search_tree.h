/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/05
 * Update : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/validate-binary-search-tree/
 * Problem:	Validate Binary Search Tree
 *
 */
#include <stdio.h>
#include <stack>
using std::stack;

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
   bool isValidBST(TreeNode* root) {
     return recursive(root, INT64_MIN, INT64_MAX);
   }

 private:
   bool recursive(TreeNode* root, int64_t lower, int64_t upper) {
     if (root == nullptr) {
       return true;
     }
     if (root->val <= lower || root->val >= upper) {
       return false;
     }
     return recursive(root->left, lower, root->val) && recursive(root->right, root->val, upper);
   }

   bool nonRecursive(TreeNode* root) {
     stack<TreeNode *> st;
     TreeNode* node = root;
     TreeNode* prev = nullptr;
     while (node != nullptr || !st.empty()) {
       if (node != nullptr) {
         st.push(node);
         node = node->left;
       } else {
         node = st.top();
         st.pop();
         if (prev != nullptr && node->val <= prev->val) {
           return false;
         }
         prev = node;
         node = node->right;
       }
     }
     return true;
   }
};
