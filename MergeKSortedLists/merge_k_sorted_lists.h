/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/01
 *
 * Source : https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * Problem:	Merge K Sorted Lists
 *
 */
#include <vector>
#include <stack>
using std::vector;
using std::stack;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
   ListNode* mergeKLists(vector<ListNode*>& lists) {
     if (lists.empty()) {
       return nullptr;
     }

     int sz = lists.size();
     while (sz > 1) {
       int j = 0;
       for (int i = 0; i < sz; i += 2) {
         lists[j++] = mergeTwoLists(lists[i], i + 1 < sz ? lists[i + 1] : nullptr);
       }
       sz = (sz + 1) / 2;
     }
     return lists.front();
   }

 private:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     if (list1 == nullptr) {
       return list2;
     }
     if (list2 == nullptr) {
       return list1;
     }

     ListNode head;
     ListNode* tail = &head;
     while (list1 != nullptr && list2 != nullptr) {
       if (list1->val < list2->val) {
         tail->next = list1;
         list1 = list1->next;
       } else {
         tail->next = list2;
         list2 = list2->next;
       }
       tail = tail->next;
     }

     if (list1 != nullptr) {
       tail->next = list1;
     } else if (list2 != nullptr) {
       tail->next = list2;
     }

     return head.next;
   }
};
