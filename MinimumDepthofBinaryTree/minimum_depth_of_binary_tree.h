/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 * Problem:	Minimum Depth of Binary Tree
 * Description: 
 *	Given a binary tree, find its minimum depth.  
 *	The minimum depth is the number of nodes along the shortest path 
 *	from the root node down to the nearest leaf node.
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
		int minDepth(TreeNode *root) {
			if (root == NULL) {
				return 0;
			}
			if (root->left == NULL && root->right == NULL) {
				return 1;
			}
			if (root->left == NULL && root->right != NULL) {
				return minDepth(root->right) + 1;
			}
			if (root->left != NULL && root->right == NULL) {
				return minDepth(root->left) + 1;
			}

			int left_depth = minDepth(root->left);
			int right_depth = minDepth(root->right);
			return left_depth < right_depth ? left_depth + 1 : right_depth + 1;
		}
};
