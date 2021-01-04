/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 * Update : 2021/01/04
 *
 * Source : https://leetcode-cn.com/problems/partition-list/
 * Problem:	Partition List
 *
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
   ListNode *partition(ListNode *head, int x) {
     ListNode* front_head = NULL;
     ListNode* front_tail = NULL;
     ListNode* back_head = NULL;
     ListNode* back_tail = NULL;

     ListNode* curr = head;
     while (curr != NULL) {
       if (curr->val < x) {
         if (front_head == NULL) {
           front_head = curr;
         } else {
           front_tail->next = curr;
         }
         front_tail = curr;
       } else {
         if (back_head == NULL) {
           back_head = curr;
         } else {
           back_tail->next = curr;
         }
         back_tail = curr;
       }
       curr = curr->next;
     }

     if (front_head != NULL) {
       front_tail->next = back_head;
     } else {
       front_head = back_head;
     }
     if (back_tail != NULL) {
       back_tail->next = NULL;
     }

     return front_head;
   }
};
