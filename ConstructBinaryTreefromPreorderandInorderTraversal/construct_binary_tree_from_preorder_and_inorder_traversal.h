/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Problem:	Construct Binary Tree from Preorder and Inorder Traversal
 * Description: 
 *	Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 *	You may assume that duplicates do not exist in the tree.
 *               
 */
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			if (preorder.empty() || inorder.empty()) {
				return NULL;
			}
			return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
		}

		TreeNode *build(vector<int> &preorder, int i, int j, vector<int> &inorder, int m, int n) {
			if (i == j) {
				return new TreeNode(preorder[i]);
			}

			TreeNode *node = new TreeNode(preorder[i]);
			int root = find(inorder, preorder[i], m, n);
			if (root == m) {
				node->right = build(preorder, i+1, j, inorder, m+1, n);
			}
			else if (root == n) {
				node->left = build(preorder, i+1, j, inorder, m, n-1);
			}
			else {
				node->left = build(preorder, i+1, (i+1)+(root-m-1), inorder, m, root-1);
				node->right = build(preorder, (i+1)+(root-m-1)+1, j, inorder, root+1, n);
			}

			return node;
		}

		int find(vector<int> &order, int val, int i, int j) {
			for (; i < j; i++) {
				if (order[i] == val) {
					return i;
				}
			}
			return j;
		}

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
