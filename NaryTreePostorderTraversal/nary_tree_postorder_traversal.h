/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/03
 *
 * Source : https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 * Problem: N-ary Tree Postorder Traversal
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
   vector<int> postorder(Node* root) {
     vector<int> vec;
     stack<NodeEx> st;
     while (root != nullptr || !st.empty()) {
       if (root != nullptr) {
         st.push(NodeEx(root, 0));
         root = root->children.empty() ? nullptr : root->children[0];
       } else {
         NodeEx node_ex = st.top();
         st.pop();
         ++node_ex.nth;
         if (node_ex.nth < node_ex.node->children.size()) {
           root = node_ex.node->children[node_ex.nth];
           st.push(node_ex);
         } else {
           vec.push_back(node_ex.node->val);
         }
       }
     }
     return vec;
   }

 private:
   struct NodeEx {
     Node* node;
     int nth;
     NodeEx() : node(nullptr), nth(0) {}
     NodeEx(Node* n, int i) : node(n), nth(i) {}
   };
};
