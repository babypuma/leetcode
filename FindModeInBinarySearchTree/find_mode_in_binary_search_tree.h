/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 * Problem:	Find Mode in Binary Search Tree
 *               
 */
#include <stack>
#include <vector>
using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
   vector<int> findMode(TreeNode* root) {
     vector<int> mode;
     if (root == NULL) {
       return mode;
     }

     int model_feature = 0;
     TreeNode* prev = NULL;
     int count = 0;
     stack<TreeNode*> st;
     TreeNode* node = root;
     while (node != NULL || !st.empty()) {
       if (node != NULL) {
         st.push(node);
         node = node->left;
       } else {
         node = st.top();
         st.pop();
         if (prev != NULL) {
           if (prev->val != node->val) {
             if (count > model_feature) {
               vector<int>().swap(mode);
               model_feature = count;
               mode.push_back(prev->val);
             } else if (count == model_feature) {
               mode.push_back(prev->val);
             }
             count = 0;
           }
         }
         ++count;
         prev = node;
         node = node->right;
       }
     }

     if (mode.empty()) {
       mode.push_back(prev->val);
     } else if (count == model_feature) {
       mode.push_back(prev->val);
     } else if (count > model_feature) {
       vector<int>().swap(mode);
       mode.push_back(prev->val);
     }

     return mode;
   }
};
