/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/05
 *
 * Source : https://oj.leetcode.com/problems/reverse-linked-list-ii/
 * Problem:	Reverse Linked List II
 * Description: 
 *	Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 	For example:
 *	Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *	return 1->4->3->2->5->NULL.
 * Note:
 *	Given m, n satisfy the following condition:
 *	1 ≤ m ≤ n ≤ length of list.
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
		ListNode *reverseBetween(ListNode *head, int m, int n) {
			if (head == NULL || head->next == NULL || m == n) {
				return head;
			}

			ListNode *front = head;
			int i;
			int wait_point = (m > 1) ? (n - m) + 1 : n - 1;
			for (i = 0; i < wait_point; i++) {
				front = front->next;	
			}
			
			ListNode *new_head; 
			ListNode *new_tail;
			if (m > 1) {
				ListNode *back = head;
				for (; i < n - 1; i++) {
					front = front->next;
					back = back->next;
				}
				new_head = back->next;
				back->next = front->next;
				front->next = NULL;
				reverse(new_head, new_tail);

				new_tail->next = back->next;
				back->next = new_head;
			}
			else {
				new_head = head;
				head = front->next;
				front->next = NULL;
				reverse(new_head, new_tail);
				new_tail->next = head;
				head = new_head;
			}

			return head;
		}

		void reverse(ListNode *&head, ListNode *&tail) {
			if (head == NULL || head->next == NULL) {
				return;
			}

			tail = head;
			ListNode *node = head;
			ListNode *next = head->next;
			tail->next = NULL;
			while (next != NULL) {
				node = next;
				next = next->next;
				node->next = head;
				head = node;
			}
		}
};
