/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 * Problem:	Binary Tree Inorder Traversal
 * Description: 
 *	Given a binary tree, return the inorder traversal of its nodes' values.
 *
 */
#include <stdio.h>
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
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> vec;
			stack<TreeNode *> st;
			while (root != NULL || !st.empty()) {
				while (root != NULL) {
					st.push(root);
					root = root->left;
				}

				if (root == NULL) {
					root = st.top();
					st.pop();
					vec.push_back(root->val);
					root = root->right;
				}
			}

			return vec;
		}
};
