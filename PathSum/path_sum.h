/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/14
 *
 * Source : https://oj.leetcode.com/problems/path-sum/
 * Problem:	Path Sum
 * Description:
 *	Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
 *	all the values along the path equals the given sum.
 *	For example:
 *	Given the below binary tree and sum = 22,
 *			           5
 *					  / \
 *					 4   8
 *					/   / \
 *				   11  13  4
 *				  /  \      \
 *				 7    2      1 
 *	return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

enum status {
	st_left,
	st_right,
};

struct ExTreeNode {
	TreeNode *tn;
	status st;
	ExTreeNode(TreeNode *node) : tn(node), st(st_left) {}
};

class Solution {
	public:
		bool hasPathSum(TreeNode *root, int sum) {
			int curr_sum = 0;
			stack<ExTreeNode *> st;	
			ExTreeNode *node;
			while (!st.empty() || root != NULL) {
				while (root != NULL) {
					curr_sum += root->val;
					node = new ExTreeNode(root);
					st.push(node);
					root = root->left;
				}
				node = st.top();
				st.pop();
				curr_sum -= node->tn->val;

				if (node->st == st_left) {
					curr_sum += node->tn->val;
					node->st = st_right;
					st.push(node);
					root = node->tn->right;
				}
				else {
					if (isLeaf(node->tn) && curr_sum + node->tn->val == sum) {
						return true;
					}
				}
			}

			return false;
		}

		bool isLeaf(TreeNode *node) {
			return node != NULL && node->left == NULL && node->right == NULL;
		}
};
