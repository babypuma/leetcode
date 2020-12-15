/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/13
 * Update : 2020/12/15
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

 private:
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

   void getAncestor(TreeNode* root, TreeNode* tn, deque<TreeNode*>& que) {
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
