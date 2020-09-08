/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/08
 *
 * Source : https://leetcode.com/problems/binary-search-tree-iterator/
 * Problem:	Binary Search Tree Iterator
 *
 */
#include <stack>
#include <vector>
using std::stack;
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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) : curr_(0) {
      inOrderTraversal(root);
    }

    /** @return the next smallest number */
    int next() {
      return vec_[curr_++]->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return curr_ < vec_.size();
    }

private:
    void inOrderTraversal(TreeNode* root) {
      stack<TreeNode*> st;
      TreeNode* node = root;
      while (!st.empty() || node != nullptr) {
        if (node != nullptr) {
          st.push(node);
          node = node->left;
        } else {
          node = st.top();
          st.pop();
          // visit node
          vec_.push_back(node);
          node = node->right;
        }
      }
    }

private:
    int curr_;
    vector<TreeNode*> vec_;
};
