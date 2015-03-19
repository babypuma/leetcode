/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 * Problem:	Binary Tree Maximum Path Sum
 * Description: 
 *	Given a binary tree, find the maximum path sum.
 * 	The path may start and end at any node in the tree.
 * 	For example:
 *	Given the below binary tree,
 * 			   1
 * 			  / \ 
 *			 2   3
 * 	Return 6.
 *
 */
#include <stdio.h>
#include <stack>
using std::stack;

#define INT32_MIN 0x80000000

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
		int maxPathSum(TreeNode *root) {
			int max = INT32_MIN;
			int curr_max = INT32_MIN;
			stack<ExTreeNode *> st;						
			ExTreeNode *node;
			while (!st.empty() || root != NULL) {
				while (root != NULL) {
					node = new ExTreeNode(root);
					st.push(node);
					root = root->left;
				}
				node = st.top();
				st.pop();
				if (node->st == st_left) {
					node->st = st_right;
					st.push(node);
					root = node->tn->right;
				}
				else {
					if (node->tn->left != NULL && node->tn->right != NULL) {
						if (node->tn->left->val >= node->tn->right->val) {
							if (node->tn->left->val > 0) {
								node->tn->val += node->tn->left->val;
							}
							curr_max = node->tn->val;
							if (node->tn->right->val > 0) {
								curr_max += node->tn->right->val;
							}
						}
						else {
							if (node->tn->right->val > 0) {
								node->tn->val += node->tn->right->val;
							}
							curr_max = node->tn->val;
							if (node->tn->left->val > 0) {
								curr_max += node->tn->left->val;
							}
						}
					}
					else {
						if (node->tn->left != NULL && node->tn->left->val > 0) {
							node->tn->val += node->tn->left->val;
						}
						else if (node->tn->right != NULL && node->tn->right->val > 0) {
							node->tn->val += node->tn->right->val;
						}
						curr_max = node->tn->val;
					}

					if (curr_max > max) {
						max = curr_max;
					}
				}
			}

			return max;
		}
};
