/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/19
 *
 * Source : https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * Problem: Construct Binary Search Tree from Preorder Traversal
 *               
 */
#include <vector>
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
   TreeNode* bstFromPreorder(vector<int>& preorder) {
     return buildBSTFromPreorder(preorder, 0, preorder.size() - 1);
   }

 private:
   TreeNode* buildBSTFromPreorder(vector<int>& preorder, int i, int j) {
     if (i > j) {
       return nullptr;
     }

     int root_val = preorder[i];
     int k = i;
     while (k <= j) {
       if (preorder[k] > root_val) {
         break;
       }
       ++k;
     }

     TreeNode* root = new TreeNode(root_val);
     root->left = buildBSTFromPreorder(preorder, i + 1, k - 1);
     root->right = buildBSTFromPreorder(preorder, k, j);
     return root;
   }
};
