/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Problem:	Populating Next Right Pointers in Each Node
 * Description: 
 *	Given a binary tree
 * 	struct TreeLinkNode { 
 *		TreeLinkNode *left; 
 *		TreeLinkNode *right; 
 *		TreeLinkNode *next; 
 *	} 
 *	Populate each next pointer to point to its next right node. 
 *	If there is no next right node, the next pointer should be set to NULL.  
 *	Initially, all next pointers are set to NULL.  
 * Note: 
 *	You may only use constant extra space.  You may assume that it is a perfect binary tree 
 *	(ie, all leaves are at the same level, and every parent has two children).
 *
 */
#include <stdio.h>
#include <queue>
using std::queue;

struct TreeLinkNode {
 	int val;
 	TreeLinkNode *left, *right, *next;
 	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if (root == NULL) {
				return;
			}
			queue<TreeLinkNode *> que;
			TreeLinkNode *node;
			TreeLinkNode *prev = NULL;
			que.push(root);
			que.push(NULL);
			while (!que.empty()) {
				node = que.front();
				que.pop();
				if (prev != NULL) {
					prev->next = node;
				} 
				prev = node;

				if (node == NULL) {
					if (que.empty()) {
						break;
					}
					que.push(NULL);
					continue;
				}
				if (node->left != NULL) {
					que.push(node->left);
				}
				if (node->right != NULL) {
					que.push(node->right);
				}
			}
		}
};
