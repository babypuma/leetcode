/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/same-tree/
 * Problem:	Same Tree
 * Description: 
 * 	Given two binary trees, write a function to check if they are equal or not.  
 * 	Two binary trees are considered equal if they are structurally identical 
 *  and the nodes have the same value.
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
		bool isSameTree(TreeNode *p, TreeNode *q) {
			if (p == NULL && q == NULL) {
				return true;
			}
			if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
				return false;
			}

			if (p->val == q->val) {
				return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			} 
			
			return false;
		}
};
