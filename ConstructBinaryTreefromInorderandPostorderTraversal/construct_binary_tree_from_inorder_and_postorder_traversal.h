/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Update : 2021/02/19
 *
 * Source : https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Problem:	Construct Binary Tree from Inorder and Postorder Traversal 
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
   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
     return buildTreeRecursive(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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
   TreeNode *buildTreeRecursive(vector<int> &inorder, int i, int j, vector<int> &postorder, int m, int n) {
     if (i > j || j - i != n - m) {
       return nullptr;
     }

     int root_val = postorder[n];
     TreeNode* root = new TreeNode(root_val);
     int k = i;
     while (k <= j) {
       if (inorder[k] == root_val) {
         break;
       }
       ++k;
     }
     root->left = buildTreeRecursive(inorder, i, k - 1, postorder, m, k - i + m - 1);
     root->right = buildTreeRecursive(inorder, k + 1, j, postorder, k - i + m, n - 1);
     return root;
   }

   TreeNode *buildTreeNoRecursive(vector<int> &inorder, vector<int> &postorder) {
     if (inorder.empty() || postorder.empty()) {
       return NULL;
     }
     return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
   }

   TreeNode *build(vector<int> &inorder, int i, int j, vector<int> &postorder, int m, int n) {
     if (m == n) {
       return new TreeNode(postorder[n]);
     }

     TreeNode *node = new TreeNode(postorder[n]);
     int root = find(inorder, postorder[n], i, j);
     if (root == i) {
       node->right = build(inorder, i+1, j, postorder, m, n-1);
     }
     else if (root == j) {
       node->left = build(inorder, i, j-1, postorder, m, n-1);
     }
     else {
       node->left = build(inorder, i, root-1, postorder, m, m+(root-1)-i);
       node->right = build(inorder, root+1, j, postorder, (m+(root-1)-i)+1, n-1);
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
