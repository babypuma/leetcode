/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/12
 *
 * Source : https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 * Problem: Serialize and Deserialize Binary Tree
 *               
 */
#include <string>
using std::string;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
   string serialize(TreeNode* root) {
     if (root == NULL) {
       return "X";
     }
     string str;
     str += "(" + serialize(root->left) + ")";
     str += std::to_string(root->val);
     str += "(" + serialize(root->right) + ")";
     return str;
   }

   TreeNode* deserialize(string data) {
     int pos = 0;
     return parse(data, pos);
   }

 private:
   TreeNode* parse(string s, int& pos) {
     if (s[pos] == 'X') {
       ++pos;
       return NULL;
     }
     auto root = new TreeNode(0);
     root->left = parseSubtree(s, pos);
     root->val = parseInt(s, pos);
     root->right = parseSubtree(s, pos);
     return root;
   }

   int parseInt(string s, int& pos) {
     int sign = 1;
     if (s[pos] == '-') {
       sign = -1;
       ++pos;
     } else if (s[pos] == '+') {
       ++pos;
     }
     int num = 0;
     while (isdigit(s[pos])) {
       num *= 10;
       num += s[pos] - '0';
       ++pos;
     }
     return num * sign;
   }

   TreeNode* parseSubtree(string s, int& pos) {
     ++pos;
     TreeNode* sub = parse(s, pos);
     ++pos;
     return sub;
   }
};
