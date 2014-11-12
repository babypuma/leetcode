#include <stdio.h>
#include <stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum status {
	st_left,
	st_right,
};

struct ExTreeNode {
	TreeNode *tn;
	status st;	
	ExTreeNode(TreeNode *n) : tn(n), st(st_left) {}
};

class Solution {
	public:
		int maxPathSum(TreeNode *root) {
			int max = INT32_MIN;
			int curr_max = INT32_MIN;
			stack<ExTreeNode *> st;						
			ExTreeNode *node;
			while (!st.empty() || root != NULL) {
				while (root != NULL) {
					node = new ExTreeNode(root);
					st.push(node);
					root = root->left;
				}
				node = st.top();
				st.pop();
				if (node->st == st_left) {
					node->st = st_right;
					st.push(node);
					root = node->tn->right;
				}
				else {
					if (node->tn->left != NULL && node->tn->right != NULL) {
						if (node->tn->left->val >= node->tn->right->val) {
							node->tn->val += node->tn->left->val;
								printf("b 1\n");
							if (node->tn->right->val > 0) {
								curr_max = node->tn->val + node->tn->right->val;
							}
							else {
								curr_max = node->tn->val;
							}
						}
						else {
								printf("b 2\n");
							node->tn->val += node->tn->right->val;
							if (node->tn->left->val > 0) {
								curr_max = node->tn->val + node->tn->left->val;
							}
							else {
								curr_max = node->tn->val;
							}
						}
					}
					else if (node->tn->left != NULL && node->tn->right == NULL) {
								printf("b 3\n");
						node->tn->val += node->tn->left->val;
						curr_max = node->tn->val;
					}
					else if (node->tn->left == NULL && node->tn->right != NULL) {
								printf("b 4\n");
						node->tn->val += node->tn->right->val;
						curr_max = node->tn->val;
					}
					else {
								printf("b 5\n");
						curr_max = node->tn->val;
					}

					if (curr_max > max) {
						max = curr_max;
					}
				}
			}

			return max;
		}
};
