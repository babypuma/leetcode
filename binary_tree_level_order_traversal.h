/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 * Problem:	Binary Tree Level Order Traversal
 * Description: 
 * 	Given a binary tree, return the level order traversal of its nodes' values. 
 *	(ie, from left to right, level by level).
 *               
 */
#include <vector>
#include <queue>
using std::vector;
using std::queue;

struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
		vector<vector<int> > levelOrder(TreeNode *root) {
			vector<vector<int> > vec2d;
			if (root == NULL) {
				return vec2d;
			}

			queue<TreeNode *> que;
			que.push(root);
			que.push(NULL);
			vector<int> vec;
			while (!que.empty()) {
				TreeNode *node = que.front();	
				if (node == NULL) {
					vec2d.push_back(vec);
					vec.clear();

					que.pop();
					if (!que.empty()) {
						que.push(NULL);
					}
				}
				else {
					vec.push_back(node->val);
					que.pop();
					if (node->left != NULL) {
						que.push(node->left);
					}
					if (node->right != NULL) {
						que.push(node->right);
					}
				}
			}

			return vec2d;
		}
};
