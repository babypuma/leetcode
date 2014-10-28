/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Problem:	Construct Binary Tree from Inorder and Postorder Traversal 
 * Description: 
 *	Given inorder and postorder traversal of a tree, construct the binary tree.
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
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
			if (inorder.empty() || postorder.empty()) {
				return NULL;
			}
			return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
		}

		TreeNode *build(vector<int> &inorder, int i, int j, vector<int> &postorder, int m, int n) {
			if (m == n) {
				return new TreeNode(postorder[n]);
			}

			TreeNode *node = new TreeNode(postorder[n]);
			int root = find(inorder, postorder[n], i, j);
			if (root == i) {
				node->right = build(inorder, i+1, j, postorder, m, n-1);
			}
			else if (root == j) {
				node->left = build(inorder, i, j-1, postorder, m, n-1);
			}
			else {
				node->left = build(inorder, i, root-1, postorder, m, m+(root-1)-i);
				node->right = build(inorder, root+1, j, postorder, (m+(root-1)-i)+1, n-1);
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
