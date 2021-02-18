/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/07
 * Update : 2021/02/18
 *
 * Source : https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 * Problem:	Sum Root to Leaf Numbers
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
   int sumNumbers(TreeNode *root) {
     int num = 0;
     return sumNumbersNoRecursive(root, num);
   }

 private:
   int sumNumbersNoRecursive(TreeNode *root, int num) {
     if (root == nullptr) {
       return 0;
     }
     if (root->left == nullptr && root->right == nullptr) {
       return num * 10 + root->val;
     }
     if (root->left == nullptr && root->right != nullptr) {
       return sumNumbersNoRecursive(root->right, num * 10 + root->val);
     }
     if (root->left != nullptr && root->right == nullptr) {
       return sumNumbersNoRecursive(root->left, num * 10 + root->val);
     }
     return sumNumbersNoRecursive(root->left, num * 10 + root->val) +
       sumNumbersNoRecursive(root->right, num * 10 + root->val);
   }

   int sumNumbersRecursive(TreeNode *root) {
     enum status {
       st_left,
       st_right,
     };

     struct ExTreeNode {
       TreeNode *tn;
       status st;
       ExTreeNode(TreeNode *n) : tn(n), st(st_left) {}
     };

     int sum = 0;
     int number = 0;
     stack<ExTreeNode *> st; 
     ExTreeNode *node;
     while (!st.empty() || root != NULL) {
       while (root != NULL) {
         node = new ExTreeNode(root);
         st.push(node);
         number = 10 * number + root->val;
         root = root->left;
       }
       node = st.top();
       st.pop();
       number /= 10;

       if (node->st == st_left) {
         node->st = st_right;
         st.push(node);
         number = 10 * number + node->tn->val;
         root = node->tn->right;
       }
       else if (node->st == st_right) {
         if (node->tn->left == NULL && node->tn->right == NULL) {
           sum += 10 * number + node->tn->val;
         }
       }
     }

     return sum;
   }
};
