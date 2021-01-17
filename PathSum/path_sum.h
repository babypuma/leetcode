/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/14
 * Update : 2021/01/17
 *
 * Source : https://leetcode-cn.com/problems/path-sum/
 * Problem:	Path Sum
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
   bool hasPathSum(TreeNode *root, int sum) {
     if (root == NULL) {
       return false;
     }
     return pathSum(root, sum);
   }

 private:
   bool pathSum(TreeNode *root, int sum) {
     if (root->left == NULL && root->right == NULL) {
       return root->val == sum;
     }
     if (root->left != NULL && root->right != NULL) {
       return pathSum(root->left, sum - root->val) || pathSum(root->right, sum - root->val);
     } else if (root->left != NULL) {
       return pathSum(root->left, sum - root->val);
     } else if (root->right != NULL) {
       return pathSum(root->right, sum - root->val);
     }
   }
};
