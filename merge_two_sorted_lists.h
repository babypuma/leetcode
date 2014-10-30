/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/merge-two-sorted-lists/
 * Problem:	Merge Two Sorted Lists
 * Description: 
 *	Merge two sorted linked lists and return it as a new list. 
 *	The new list should be made by splicing together the nodes of the first two lists.               
 *
 */
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			if (l1 == NULL) {
				return l2;
			}
			if (l2 == NULL) {
				return l1;
			}

			ListNode *head;
			if (l1->val < l2->val) {
				head = l1;
				l1 = l1->next;
			}
			else {
				head = l2;
				l2 = l2->next;
			}
			ListNode *curr = head; 

			while (l1 != NULL && l2 != NULL) {
				if (l1->val < l2->val) {
					curr->next = l1;
					l1 = l1->next;
				}
				else {
					curr->next = l2;
					l2 = l2->next;
				}
				curr = curr->next;
			}

			if (l1 != NULL) {
				curr->next = l1;
			}
			else if (l2 != NULL) {
				curr->next = l2;
			}

			return head;
		}
};
