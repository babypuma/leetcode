/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Problem:	Binary Tree ZigZag Level Order Traversal
 * Description: 
 * 	Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 * 	(ie, from left to right, then right to left for the next level and alternate between).
 *               
 */
#include <vector>
#include <stack>
using std::vector;
using std::stack;

struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
		vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
			vector<vector<int> > vec2d;
			if (root == NULL) {
				return vec2d;
			}

			stack<TreeNode *> right2left;
			stack<TreeNode *> left2right;
			right2left.push(root);

			vector<int> vec;
			TreeNode *node;
			while (!right2left.empty() || !left2right.empty()) {
				while (!right2left.empty()) {
					node = right2left.top();	
					vec.push_back(node->val);
					right2left.pop();
					if (right2left.empty()) {
						vec2d.push_back(vec);
						vec.clear();
					}
					if (node->left != NULL) {
						left2right.push(node->left);
					}
					if (node->right != NULL) {
						left2right.push(node->right);
					}
				}
				while (!left2right.empty()) {
					node = left2right.top();
					vec.push_back(node->val);
					left2right.pop();
					if (left2right.empty()) {
						vec2d.push_back(vec);
						vec.clear();
					}
					if (node->right != NULL) {
						right2left.push(node->right);
					}
					if (node->left != NULL) {
						right2left.push(node->left);
					}
				}
			}

			return vec2d;
		}
};
