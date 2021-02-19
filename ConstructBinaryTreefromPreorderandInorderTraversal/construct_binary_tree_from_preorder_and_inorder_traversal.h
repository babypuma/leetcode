/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Update : 2021/02/19
 *
 * Source : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Problem:	Construct Binary Tree from Preorder and Inorder Traversal
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
   TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
     return buildTreeRecursive(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
   }

   bool isSameTree(TreeNode *p, TreeNode *q) {
     if (p == NULL && q == NULL) {
       return true;
     }
     if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
       return false;
     }

     if (p->val == q->val) {
       return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
     } 

     return false;
   }

 private:
   TreeNode *buildTreeRecursive(vector<int> &preorder, int i, int j, vector<int> &inorder, int m, int n) {
     if (i > j || j - i != n - m) {
       return nullptr;
     }

     int root_val = preorder[i];
     TreeNode* root = new TreeNode(root_val);
     int k = m;
     while (k <= n) {
       if (inorder[k] == root_val) {
         break;
       }
       ++k;
     }

     root->left = buildTreeRecursive(preorder, i + 1, k - m + i, inorder, m, k - 1);
     root->right = buildTreeRecursive(preorder, k - m + i + 1, j, inorder, k + 1, n);
     return root;
   }

   TreeNode *buildTreeNoRecursive(vector<int> &preorder, vector<int> &inorder) {
     if (preorder.empty() || inorder.empty()) {
       return NULL;
     }
     return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
   }

   TreeNode *build(vector<int> &preorder, int i, int j, vector<int> &inorder, int m, int n) {
     if (i == j) {
       return new TreeNode(preorder[i]);
     }

     TreeNode *node = new TreeNode(preorder[i]);
     int root = find(inorder, preorder[i], m, n);
     if (root == m) {
       node->right = build(preorder, i+1, j, inorder, m+1, n);
     }
     else if (root == n) {
       node->left = build(preorder, i+1, j, inorder, m, n-1);
     }
     else {
       node->left = build(preorder, i+1, (i+1)+(root-m-1), inorder, m, root-1);
       node->right = build(preorder, (i+1)+(root-m-1)+1, j, inorder, root+1, n);
     }

     return node;
   }

   int find(vector<int> &order, int val, int i, int j) {
     for (; i < j; i++) {
       if (order[i] == val) {
         return i;
       }
     }
     return j;
   }
};
