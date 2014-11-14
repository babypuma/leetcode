#include <stdio.h>
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
		void flatten(TreeNode *root) {
			stack<TreeNode *> st;			
			TreeNode *dummy = new TreeNode(0);
			TreeNode *prev = dummy;
			while (root != NULL || !st.empty()) {
				while (root != NULL) {
					prev->right = root;
					if (root->right != NULL) {
						st.push(root->right);
					}
					root->right = root->left;

					prev = root;
					root = root->right;
				}

				root = st.top();
				st.pop();
			}
		}
};
