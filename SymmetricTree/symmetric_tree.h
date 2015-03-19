/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/symmetric-tree/
 * Problem:	Symmetric Tree
 * Description: 
 * 	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
		bool isSymmetric(TreeNode *root) {
			if (root == NULL || (root->left == NULL && root->right == NULL)) {
				return true;
			}

			return symmetric(root->left, root->right);
		}

		bool symmetric(TreeNode *p, TreeNode *q) {
			if (p == NULL && q == NULL) {
				return true;
			}
			if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
				return false;
			}

			if (p->val == q->val) {
				return symmetric(p->left, q->right) && symmetric(p->right, q->left);
			} 
			
			return false;
		}
};
