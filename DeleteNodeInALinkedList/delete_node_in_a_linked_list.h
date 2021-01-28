/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * Problem: Delete Node in a Linked List
 *               
 */
#include <vector>
using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
   void deleteNode(ListNode* node) {
     node->val = node->next->val;
     ListNode *deleted = node->next;
     node->next = node->next->next;
     delete deleted;
   }
};
