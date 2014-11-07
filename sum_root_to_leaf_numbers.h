/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/07
 *
 * Source : https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 * Problem:	Sum Root to Leaf Numbers
 * Description: 
 *	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *	An example is the root-to-leaf path 1->2->3 which represents the number 123.  
 *	Find the total sum of all root-to-leaf numbers.  
 *	For example, 
 *	    1
 *	   / \ 
 *	  2   3 
 *	The root-to-leaf path 1->2 represents the number 12.  
 *	The root-to-leaf path 1->3 represents the number 13.  
 *	Return the sum = 12 + 13 = 25.
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
	ExTreeNode(TreeNode *n) : tn(n), st(st_left) {}
};

class Solution {
	public:
		int sumNumbers(TreeNode *root) {
			int sum = 0;
			int number = 0;
			stack<ExTreeNode *> st; 
			ExTreeNode *node;
			while (!st.empty() || root != NULL) {
				while (root != NULL) {
					node = new ExTreeNode(root);
					st.push(node);
					number = 10 * number + root->val;
					root = root->left;
				}
				node = st.top();
				st.pop();
				number /= 10;

				if (node->st == st_left) {
					node->st = st_right;
					st.push(node);
					number = 10 * number + node->tn->val;
					root = node->tn->right;
				}
				else if (node->st == st_right) {
					if (node->tn->left == NULL && node->tn->right == NULL) {
						sum += 10 * number + node->tn->val;
					}
				}
			}

			return sum;
		}
};
