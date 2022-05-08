/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/08
 *
 * Source : https://leetcode-cn.com/contest/weekly-contest-292/problems/count-nodes-equal-to-average-of-subtree/
 * Problem: Count Nodes Equal to Average of Subtree
 *
 */
#include <vector>
#include <stack>
using std::vector;
using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum status {
  st_unknown,
  st_left,
  st_right,
};

struct ExTreeNode {
  TreeNode *tn;
  status st;
  int sum;
  int child_cnt;
  ExTreeNode() : tn(nullptr), st(st_unknown), sum(0), child_cnt(0) {}
  ExTreeNode(TreeNode *n) : tn(n), st(st_left), sum(n->val), child_cnt(1) {}
};

class Solution {
 public:
   int averageOfSubtree(TreeNode* root) {
     int count = 0;
     int sum = 0;
     vector<ExTreeNode> vec;
     stack<ExTreeNode> st; 
     while (root != nullptr || !st.empty()) {
       if (root != nullptr) {
         st.push(ExTreeNode(root));
         root = root->left;
       } else {
         ExTreeNode node = st.top();
         st.pop();
         if (node.st == st_left) {
           if (!vec.empty() && node.tn->left != nullptr) {
             const ExTreeNode& l = vec.back();
             node.sum += l.sum;
             node.child_cnt += l.child_cnt;
           }
           node.st = st_right;
           st.push(node);
           root = node.tn->right;
         } else {
           if (!vec.empty() && node.tn->right != nullptr) {
             const ExTreeNode& r = vec.back();
             node.sum += r.sum;
             node.child_cnt += r.child_cnt;
           }
           if (node.sum / node.child_cnt == node.tn->val) {
             ++count;
           }
           vec.push_back(node);
         }
       }
     }
     return count;
   }
};
