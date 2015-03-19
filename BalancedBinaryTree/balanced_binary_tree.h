/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/balanced-binary-tree/
 * Problem:	Balanced Binary Tree
 * Description:
 *	Given a binary tree, determine if it is height-balanced.  
 *	For this problem, a height-balanced binary tree is defined as a binary tree 
 *	in which the depth of the two subtrees of every node never differ by more than 1.
 *
 */
#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isBalanced(TreeNode *root) {
			balanced = true;
			depth(root);
			return balanced;
		}
		
		int depth(TreeNode *node) {
			if (node == NULL) {
				return 0;
			}
			int left_depth = depth(node->left);
			int right_depth = depth(node->right);
			if (left_depth < right_depth) {
				if (right_depth - left_depth > 1) {
					balanced = false;
				}

				return right_depth + 1;
			}
			else {
				if (left_depth - right_depth > 1) {
					balanced = false;
				}

				return left_depth + 1;
			}
		}
	private:
		bool balanced;
};
