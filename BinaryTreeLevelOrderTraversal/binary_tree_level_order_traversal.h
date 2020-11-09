/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Update : 2020/11/09
 *
 * Source : https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * Problem:	Binary Tree Level Order Traversal
 *               
 */
#include <vector>
#include <queue>
using std::vector;
using std::queue;

struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
   vector<vector<int> > levelOrder(TreeNode* root) {
     vector<vector<int> > vec;
     if (root == NULL) {
       return vec;
     }
     queue<TreeNode*> que;
     que.push(root);
     que.push(NULL);
     vec.push_back(vector<int>());
     while (!que.empty()) {
       TreeNode *node = que.front();
       que.pop();
       if (node != NULL) {
         vec.back().push_back(node->val);
         if (node->left != NULL) {
           que.push(node->left);
         }
         if (node->right != NULL) {
           que.push(node->right);
         }
       } else if (!que.empty()) {
         que.push(NULL);
         vec.push_back(vector<int>());
       }
     }

     return vec;
   }
};
