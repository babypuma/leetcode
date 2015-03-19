/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/31
 *
 * Source : https://oj.leetcode.com/problems/reorder-list/
 * Problem:	Reorder List
 * Description: 
 *	Given a singly linked list L: L0→L1→…→Ln-1→Ln, 
 *	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… 
 *	You must do this in-place without altering the nodes' values.
 *
 *	For example,
 *	Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
		void reorderList(ListNode *head) {
			size_t len = length(head);
			if (len < 3) {
				return;
			}

			ListNode *node = head;
			for (size_t i = 0; i < len/2; i++) {
				node = node->next;
			}
			ListNode *new_head = node->next;
			node->next = NULL;
			new_head = reverse(new_head);
			
			head = merge(head, new_head);
		}

		size_t length(ListNode *head) {
			size_t size = 0;
			while (head != NULL) {
				head = head->next;
				size++;
			}
			return size;
		}

		ListNode *reverse(ListNode *head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}
			ListNode *new_head = head;
			head = head->next; 
			new_head->next = NULL;
			ListNode *node;
			while (head != NULL) {
				node = head;
				head = head->next;
				node->next = new_head;
				new_head = node;
			}

			return new_head;
		}

		ListNode *merge(ListNode *head1, ListNode *head2) {
			ListNode *node1 = head1;
			ListNode *node2;
			while (head2 != NULL) {
				node2 = head2;
				head2 = head2->next;
				node2->next = node1->next;
				node1->next = node2;
				node1 = node2->next;
			}

			return head1;
		}
};
