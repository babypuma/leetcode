/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/13
 *
 * Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Problem:	Kth Smallest Element in a BST
 * Description: 
 *	Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note: 
 *	You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 *	What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
 *	How would you optimize the kthSmallest routine?
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

class Solution {
	public:
	    int kthSmallest(TreeNode* root, int k) {
			stack<TreeNode *> st;
			int n = 0;			        
			while (!st.empty() || root != NULL) {
				while (root != NULL) {
					st.push(root);
					root = root->left;
				}
				
				root = st.top();
				st.pop();
				if (++n == k) {
					return root->val;
				}
				root = root->right;
			}
		}
};
