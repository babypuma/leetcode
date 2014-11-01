/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/sort-list/
 * Problem:	Sort List
 * Description: 
 *	Sort a linked list in O(n log n) time using constant space complexity.
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
		ListNode *sortList(ListNode *head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}
			ListNode *a = head;
			ListNode *b = head;
			while (b->next != NULL && b->next->next != NULL) {
				a = a->next;
				b = b->next->next;
			}
			b = a->next;
			a->next = NULL;

			return merge(sortList(head), sortList(b));	
		}

		ListNode *merge(ListNode *a, ListNode *b) {
			ListNode *dummy = new ListNode(0);
			ListNode *node = dummy;
			while (a != NULL && b != NULL) {
				if (a->val < b->val) {
					node->next = a;
					a = a->next;
				}
				else {
					node->next = b;
					b = b->next;
				}
				node = node->next;
			} 
			node->next = (a != NULL) ? a : b;

			node = dummy->next;
			delete dummy;

			return node;
		}
};
