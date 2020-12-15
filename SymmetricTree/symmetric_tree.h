/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Update : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/symmetric-tree/
 * Problem:	Symmetric Tree
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
   bool isSymmetric(TreeNode* root) {
     return root == NULL || isSym(root->left, root->right);
   }

 private:
   bool isSym(TreeNode* left, TreeNode* right) {
     if (left == NULL && right == NULL) {
       return true;
     }
     if (left == NULL || right == NULL || left->val != right->val) {
       return false;
     }
     return isSym(left->left, right->right) && isSym(left->right, right->left);
   }
};
