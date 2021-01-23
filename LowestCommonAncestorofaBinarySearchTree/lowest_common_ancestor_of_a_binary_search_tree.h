/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/12
 * Update : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Problem:	Lowest Common Ancestor of a Binary Search Tree
 *
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (root == NULL || p == NULL || q == NULL) {
       return NULL;
     }
     if (p == q) {
       return p;
     }
     return p->val < q->val ? ancestor(root, p, q) : ancestor(root, q, p);
   }

 private:
   TreeNode* ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (root->val == p->val || root->val == q->val || (root->val > p->val && root->val < q->val)) {
       return root;
     }
     return root->val < p->val ? ancestor(root->right, p, q) : ancestor(root->left, p, q);
   }
};
