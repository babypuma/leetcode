/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/05
 *
 * Source : https://oj.leetcode.com/problems/validate-binary-search-tree/
 * Problem:	Validate Binary Search Tree
 * Description: 
 *	Given a binary tree, determine if it is a valid binary search tree (BST).
 * 	Assume a BST is defined as follows:
 * 	The left subtree of a node contains only nodes with keys less than the node's key.
 *	The right subtree of a node contains only nodes with keys greater than the node's key.
 *	Both the left and right subtrees must also be binary search trees.
 *
 */
#include <stdio.h>
#include <stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isValidBST(TreeNode *root) {
			return inorderSearch(root);
		}

		bool inorderSearch(TreeNode *root) {
			stack<TreeNode *> st;
			TreeNode *prev = NULL;
			TreeNode *node = root;
			while (!st.empty() || node != NULL) {
				while (node != NULL) {
					st.push(node);
					node = node->left;
				}

				if (node == NULL) {
					node = st.top();
					st.pop();
					if (prev != NULL) {
						if (prev->val < node->val) {
							prev = node;
						}
						else {
							return false;
						}
					}
					else {
						prev = node;
					}
					node = node->right;
				}
			}

			return true;
		}
};
