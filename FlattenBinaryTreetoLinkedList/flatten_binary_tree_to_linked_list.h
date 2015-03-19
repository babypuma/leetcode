/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/15
 *
 * Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Problem:	Flatten Binary Tree to Linked List
 * Description:
 *	Given a binary tree, flatten it to a linked list in-place.
 *	For example, 
 *	Given 
 *				1
 *			   / \
 *			  2   5
 *			 / \   \
 *			3   4   6
 *	The flattened tree should look like:
 *		1
 *		 \
 *		  2
 *		   \
 *			3
 *			 \
 *			  4
 *			   \
 *				5
 *				 \
 *				  6
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
		void flatten(TreeNode *root) {
			stack<TreeNode *> st;			
			TreeNode *dummy = new TreeNode(0);
			TreeNode *prev = dummy;
			while (root != NULL || !st.empty()) {
				if (root == NULL) {
					root = st.top();
					st.pop();
				}
				if (root->right != NULL) {
					st.push(root->right);
				}
				prev->right = root;
				prev->left = NULL;
				prev = root;
				root = root->left;
			}

			delete dummy;
		}
};
