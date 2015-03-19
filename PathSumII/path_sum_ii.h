/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/14
 *
 * Source : https://oj.leetcode.com/problems/path-sum-ii/
 * Problem:	Path Sum II
 * Description:
 *	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * 	For example: 
 *	Given the below binary tree and sum = 22, 
 *						5 
 *					   / \
 *					  4   8
 *					 /   / \
 *					11  13  4
 *				   /  \    / \
 *				  7    2  5   1
 *	return 
 *	[
 *	  [5,4,11,2],
 *    [5,8,4,5]
 *  ]
 *
 */
#include <stdio.h>
#include <vector>
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
	ExTreeNode(TreeNode *node) : tn(node), st(st_left) {}
};

class Solution {
	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum) {
			vector<vector<int> > vec2d;
			int curr_sum = 0;
			vector<ExTreeNode *> vec;	
			ExTreeNode *node;
			while (!vec.empty() || root != NULL) {
				while (root != NULL) {
					curr_sum += root->val;
					node = new ExTreeNode(root);
					vec.push_back(node);
					root = root->left;
				}
				node = vec.back();
				vec.pop_back();
				curr_sum -= node->tn->val;

				if (node->st == st_left) {
					curr_sum += node->tn->val;
					node->st = st_right;
					vec.push_back(node);
					root = node->tn->right;
				}
				else {
					if (isLeaf(node->tn) && curr_sum + node->tn->val == sum) {
						vector<int> v;
						for (vector<ExTreeNode *>::iterator it = vec.begin(); it != vec.end(); it++) {
							v.push_back((*it)->tn->val);
						}
						v.push_back(node->tn->val);
						vec2d.push_back(v);
					}
				}
			}

			return vec2d;
		}

		bool isLeaf(TreeNode *node) {
			return node != NULL && node->left == NULL && node->right == NULL;
		}
};
