/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/03
 *
 * Source : https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
 * Problem: N-ary Tree Preorder Traversal
 *               
 */
#include <stack>
#include <vector>
using std::stack;
using std::vector;

class Node {
 public:
   int val;
   vector<Node*> children;
   Node() {}
   Node(int _val) {
     val = _val;
   }
   Node(int _val, vector<Node*> _children) {
     val = _val;
     children = _children;
   }
};

class Solution {
 public:
   vector<int> preorder(Node* root) {
     vector<int> vec;
     stack<Node*> st;
     while (root != nullptr || !st.empty()) {
       if (root != nullptr) {
         vec.push_back(root->val);
         int sz = root->children.size();
         for (int i = sz - 1; i > 0; --i) {
           st.push(root->children[i]);
         }
         root = ((sz == 0) ? nullptr : root->children[0]);
       } else {
         root = st.top();
         st.pop();
       }
     }
     return vec;
   }
};
