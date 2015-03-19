/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * Problem:	Binary Tree Level Order Traversal II
 * Description: 
 * 	Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 *	(ie, from left to right, level by level from leaf to root).
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
		vector<vector<int> > levelOrderBottom(TreeNode *root) {
			int max_depth = maxDepth(root);
			vector<vector<int> > vec2d(max_depth);
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
					vec2d[--max_depth] = vec;
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

		int maxDepth(TreeNode *root) {
			if (root == NULL) {
				return 0;
			}
			int left_depth = maxDepth(root->left);
			int right_depth = maxDepth(root->right);

			return left_depth > right_depth ? left_depth+1 : right_depth+1;
		}
};
