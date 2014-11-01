/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 * Problem:	Binary Tree Postorder Traversal
 * Description: 
 *	Given a binary tree, return the postorder traversal of its nodes' values.
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

enum status {
	st_left,
	st_right,
};

struct ExTreeNode {
	TreeNode *tn;
	status st;
	ExTreeNode(TreeNode *n) : tn(n), st(st_left) {}
};

class Solution {
	public:
		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> vec;
			stack<ExTreeNode *> st; 
			ExTreeNode *node;
			while (root != NULL || !st.empty()) {
				while (root != NULL) {
					node = new ExTreeNode(root);
					st.push(node);
					root = root->left;
				}

				if (root == NULL) {
					node = st.top();
					st.pop();
					if (node->st == st_left) {
						node->st = st_right;
						st.push(node);
						root = node->tn->right;
					}
					else {
						vec.push_back(node->tn->val);
					}
				}
			}

			return vec;
		}

};
