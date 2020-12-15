/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/diameter-of-binary-tree/
 * Problem: Diameter of Binary Tree
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
   int diameterOfBinaryTree(TreeNode* root) {
     int diameter = 0;
     getDepth(root, diameter);
     return diameter;
   }

 private:
   int getDepth(TreeNode* root, int& diameter) {
     if (root == NULL) {
       return -1;
     }
     int left_depth = getDepth(root->left, diameter);
     int right_depth = getDepth(root->right, diameter);
     if (diameter < left_depth + right_depth + 2) {
       diameter = left_depth + right_depth + 2;
     }
     return std::max(left_depth, right_depth) + 1;
   }
};
