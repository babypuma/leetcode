/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/subtree-of-another-tree/
 * Problem: Subtree of Another Tree
 *               
 */
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
   bool isSubtree(TreeNode* s, TreeNode* t) {
     return dfs(s, t);
   }

 private:
   bool dfs(TreeNode* s, TreeNode* t) {
     if (s == nullptr) {
       return false;
     }
     return isSameTree(s, t) || dfs(s->left, t) || dfs(s->right, t);
   }

   bool isSameTree(TreeNode* s, TreeNode* t) {
     if (s == nullptr && t == nullptr) {
       return true;
     }
     if (s == nullptr || t == nullptr || s->val != t->val) {
       return false;
     }
     return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
   }
};
