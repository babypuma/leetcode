/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date ` : 2020/11/10
 *
 * Source : https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 * Problem:	Copy List with Random Pointer
 *               
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

// Definition for a Node.
class Node {
 public:
   int val;
   Node* next;
   Node* random;

   Node(int _val) {
     val = _val;
     next = NULL;
     random = NULL;
   }
};

class Solution {
 public:
   Node* copyRandomList(Node* head) {
     vector<Node*> origin;
     unordered_map<int64_t, int> node_idx;
     Node *node = head;
     while (node != NULL) {
       origin.push_back(node);
       node_idx[reinterpret_cast<int64_t>(node)] = origin.size() - 1;
       node = node->next;
     }
     if (origin.empty()) {
       return NULL;
     }

     vector<Node*> dest(origin.size());
     Node* next = NULL;
     for (int i = origin.size() - 1; i >= 0; --i) {
       dest[i] = new Node(origin[i]->val);
       dest[i]->next = next;
       next = dest[i];
     }
     for (int i = 0; i < origin.size(); ++i) {
       if (origin[i]->random != NULL) {
         dest[i]->random = dest[node_idx[reinterpret_cast<int64_t>(origin[i]->random)]];
       }
     }
     
     return dest[0];
   }
};
