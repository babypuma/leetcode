/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/14
 *
 * Source : https://oj.leetcode.com/problems/invert-binary-tree/
 * Problem:	Invert Binary Tree
 * Description:
 * Invert a binary tree.
 *
 * 		   4
 *       /   \
 *      2     7
 *     / \   / \ 
 *    1   3 6   9
 * to
 *         4
 *       /   \ 
 *		7     2
 *     / \   / \
 *    9   6 3   1
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using std::queue;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* invertTree(TreeNode* root) {
			return (random() % 2 == 0) ? 
				invertTree_non_recursive(root) :
				invertTree_recursive(root);
		}

	private:
		TreeNode* invertTree_recursive(TreeNode* root) {
			if (root != NULL) {
				TreeNode *tmp = invertTree(root->left);
				root->left = invertTree(root->right);
				root->right = tmp;
			}

			return root;
		}

		TreeNode* invertTree_non_recursive(TreeNode* root) {
			if (root == NULL) {
				return NULL;
			}

			queue<TreeNode *> qu;
			qu.push(root);
			while (!qu.empty()) {
				TreeNode *node = qu.front();
				qu.pop();
				TreeNode *tmp = node->right;
				node->right = node->left;
				node->left = tmp;
				if (node->left != NULL) {
					qu.push(node->left);
				}
				if (node->right != NULL) {
					qu.push(node->right);
				}
			}

			return root;
		}
};
