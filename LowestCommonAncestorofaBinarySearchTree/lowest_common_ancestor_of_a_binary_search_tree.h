/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/12
 *
 * Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Problem:	Lowest Common Ancestor of a Binary Search Tree
 * Description: 
 *	Given a binary search tree (BST), find the lowest common ancestor (LCA) of 
 *	two given nodes in the BST.
 *
 * 	According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
 *	between two nodes v and w as the lowest node in T that has both v and w as descendants 
 *	(where we allow a node to be a descendant of itself).”
 *
 * 					_______6______
 *				   /              \
 *			   ___2__          ___8__
 *			  /      \        /      \
 * 			 0      _4       7       9
 *					/  \
 *				   3   5
 * 	For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
 *	Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of 
 *	itself according to the LCA definition.
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
   	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == NULL || p == NULL || q == NULL) {
				return NULL;
			}
			if (p == q) {
				return p;
			}
			if (p->val > q->val) {
				TreeNode *t = p;
				p = q;
				q = t;
			}
			return ancestor(root, p, q);
		}

	private:
		TreeNode* ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root->val == p->val 
				|| root->val == q->val 
				|| (root->val > p->val && root->val < q->val)) {
				return root;
			}
			if (root->val < p->val) {
				return ancestor(root->right, p, q);
			}
			if (root->val > q->val) {
				return ancestor(root->left, p, q);
			}
		}
};
