/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/13
 * Update : 2020/12/15
 * Update : 2021/02/18
 *
 * Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Problem:	Lowest Common Ancestor of a Binary Tree
 *
 */
#include <stack>
#include <deque>
using std::stack;
using std::deque;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (root == p || root == q) {
       return root;
     }
     TreeNode* node1 = lowestCommonAncestorRecursive(root->left, p);
     TreeNode* node2 = lowestCommonAncestorRecursive(root->left, q);
     if (node1 != NULL && node2 != NULL) {
       return lowestCommonAncestor(root->left, p, q);
     }
     if (node1 == NULL && node2 == NULL) {
       return lowestCommonAncestor(root->right, p, q);
     }
     return root;
   }

 private:
   TreeNode* lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p) {
     if (root == NULL) {
       return NULL;
     }
     if (root == p) {
       return root;
     }
     TreeNode* node = lowestCommonAncestorRecursive(root->left, p);
     if (node != NULL) {
       return node;
     }
     return lowestCommonAncestorRecursive(root->right, p);
   }

   TreeNode* lowestCommonAncestorNoRecursive(TreeNode* root, TreeNode* p, TreeNode* q) {
     deque<TreeNode*> que1;
     getAncestor(root, p, que1);
     deque<TreeNode*> que2;
     getAncestor(root, q, que2);
     TreeNode* anc = NULL;
     while (!que1.empty() && !que2.empty()) {
       if (que1.front() == que2.front()) {
         anc = que1.front();
         que1.pop_front();
         que2.pop_front();
       } else {
         break;
       }
     }

     return anc;
   }

   void getAncestor(TreeNode* root, TreeNode* tn, deque<TreeNode*>& que) {
     enum NodeStatus {
       LEFT,
       RIGHT,
     };
     struct TreeNodeWrapper {
       TreeNode *node;
       NodeStatus st;
       TreeNodeWrapper(TreeNode* n, NodeStatus s) : node(n), st(s) {
       }
     };

     stack<TreeNodeWrapper> st;
     while (root != NULL || !st.empty()) {
       if (root != NULL) {
         st.push(TreeNodeWrapper(root, LEFT));
         root = root->left;
       } else {
         TreeNodeWrapper wrapper = st.top();
         if (wrapper.st == LEFT) {
           st.pop();
           // return from left child
           st.push(TreeNodeWrapper(wrapper.node, RIGHT));
           root = wrapper.node->right;
         } else {
           // return from right child, visit node
           if (wrapper.node == tn) {
             break;
           }
           st.pop();
         }
       }
     }
     while (!st.empty()) {
       TreeNodeWrapper wrapper = st.top();
       st.pop();
       que.push_front(wrapper.node);
     }
   }
};
