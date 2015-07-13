/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/13
 *
 * Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Problem:	Lowest Common Ancestor of a Binary Tree
 * Description: 
 *	Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * 	According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
 *	two nodes v and w as the lowest node in T that has both v and w as descendants 
 *	(where we allow a node to be a descendant of itself).”
 *
 * 				 _______3______
 *		        /              \
 *  		 ___5__          ___1__
 * 		    /      \        /      \
 * 	 	    6      _2       0       8
 *      		  /  \
 *				 7   4
 *
 *	For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
 *	Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant 
 *	of itself according to the LCA definition.
 *
 */
#include <stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
   	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum TravelMark {
	TM_LEFT,
	TM_RIGHT,
};

struct ExTreeNode {
	TreeNode *node;
	TravelMark mark;
	ExTreeNode(TreeNode *n, TravelMark tm = TM_LEFT) : node(n), mark(tm) {}
};

class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == NULL || p == NULL || q == NULL) {
				return NULL;
			}

			stack<TreeNode *> st1;
			stack<TreeNode *> st2;
			ancestors(root, p, st1);
			ancestors(root, q, st2);
			TreeNode *ancestor = NULL;
			while (!st1.empty() && !st2.empty()) {
				if (st1.top() != st2.top()) {
					break;
				}
				ancestor = st1.top();
				st1.pop();
				st2.pop();
			}

			return ancestor;
		}

	private:
		void ancestors(TreeNode* root, TreeNode* n, stack<TreeNode *> &ancs) {
			stack<ExTreeNode *> st;
			while (!st.empty() || root != NULL) {
				while (root != NULL) {
					if (root == n) {
						ancs.push(root);
						while (!st.empty()) {
							ancs.push(st.top()->node);
							st.pop();
						}
						return;
					}
					st.push(new ExTreeNode(root));
					root = root->left;
				}

				if (!st.empty()) {
					ExTreeNode *exnode = st.top();
					st.pop();
					if (exnode->mark == TM_LEFT) { 
						exnode->mark = TM_RIGHT;
						st.push(exnode); 
						root = exnode->node->right;
					}
					else {
						delete exnode;
					}
				}
			}
		}
};
