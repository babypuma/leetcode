/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
 * Problem: LowestCommonAncestorOfABinaryTreeIV
 *               
 */
#include <unordered_set>
#include <vector>
using std::unordered_set;
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
   TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
     unordered_set<int> values;
     for (auto& n : nodes) {
       values.insert(n->val);
     }
     return lowestCommonAncestor(root, values);
   }

 private:
   TreeNode* lowestCommonAncestor(TreeNode* root, unordered_set<int>& values) {
     if (root == nullptr) {
       return nullptr;
     }
     if (values.count(root->val) > 0) {
       return root;
     }
     TreeNode* left = lowestCommonAncestor(root->left, values);
     TreeNode* right = lowestCommonAncestor(root->right, values);
     if (left != nullptr && right != nullptr) {
       return root;
     }
     return (left != nullptr) ? left : right;
   }
};
