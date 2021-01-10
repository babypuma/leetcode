/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/10
 *
 * Source : https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/
 * Problem: Swapping Nodes in a Linked List
 *               
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
   ListNode* swapNodes(ListNode* head, int k) {
     ListNode fake_head(0, head);
     int sz = 0;
     for (ListNode* node = fake_head.next; node != NULL; node = node->next) {
       ++sz;
     }

     ListNode* forward = &fake_head;
     for (int i = 0; i < k; ++i) {
       forward = forward->next;
     }
     ListNode* backward = &fake_head;
     for (int i = 0; i < sz - k + 1; ++i) {
       backward = backward->next;
     }
     std::swap(forward->val, backward->val);

     return fake_head.next;
   }
};
