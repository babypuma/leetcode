/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 * Update : 2020/12/15
 *
 * Source : https://leetcode.com/problems/binary-tree-right-side-view/
 * Problem:	Binary Tree Right Side View
 *
 */
#include <queue>
#include <vector>
using std::queue;
using std::vector;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeNodeWrapper {
  TreeNode* node;
  int level;
  int idx;
  TreeNodeWrapper(TreeNode* n, int l, int i) : node(n), level(l), idx(i) {
  }
};

class Solution {
 public:
   vector<int> rightSideView(TreeNode* root) {
     vector<int> view;
     if (root == NULL) {
       return view;
     }

     queue<TreeNodeWrapper> que;
     que.push(TreeNodeWrapper(root, 0, 0));
     while (!que.empty()) {
       TreeNodeWrapper wrapper = que.front();
       que.pop();
       if (que.empty() || que.front().level > wrapper.level) {
         view.push_back(wrapper.node->val);
       }
       if (wrapper.node->left != NULL) {
         que.push(TreeNodeWrapper(wrapper.node->left, wrapper.level + 1, 2 * wrapper.idx + 1));
       }
       if (wrapper.node->right != NULL) {
         que.push(TreeNodeWrapper(wrapper.node->right, wrapper.level + 1, 2 * wrapper.idx + 2));
       }
     }

     return view;
   }
};
