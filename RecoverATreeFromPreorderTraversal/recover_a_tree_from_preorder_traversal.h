/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/25
 *
 * Source : https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
 * Problem: Recover a Tree From Preorder Traversal
 *               
 */
#include <string>
#include <stack>
using std::string;
using std::stack;

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
   TreeNode* recoverFromPreorder(string S) {
     int val = 0;
     int level = 0;
     size_t pos = readOneNodeVal(S, 0, val, level);
     TreeNode* root = new TreeNode(val);
     stack<StackElem> st;
     st.push(StackElem(root, level));
     while (pos < S.size()) {
       pos = readOneNodeVal(S, pos, val, level);
       StackElem prev = st.top();
       while (prev.level >= level) {
         st.pop();
         prev = st.top();
       }
       if (prev.level < level) {
         if (prev.node->left == nullptr) {
           prev.node->left = new TreeNode(val);
           st.push(StackElem(prev.node->left, level));
         } else {
           prev.node->right = new TreeNode(val);
           st.push(StackElem(prev.node->right, level));
         }
       }
     }
     return root;
   }
   
 private:
   struct StackElem {
     TreeNode* node;
     int level;
     StackElem(TreeNode* n, int l) : node(n), level(l) {}
   };

   size_t readOneNodeVal(string& str, size_t pos, int& val, int& level) {
     level = 0;
     if (pos != 0) {
       while (str[pos] == '-') {
         ++level;
         ++pos;
       }
     }
     val = 0;
     while (pos < str.size() && std::isdigit(str[pos])) {
       val = val * 10 + (str[pos] - '0');
       ++pos;
     }

     return pos;
   }
};
