/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/linked-list-cycle/
 * Problem:	Linked List Cycle
 * Description: 
 *	Given a linked list, determine if it has a cycle in it.
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
		bool hasCycle(ListNode *head) {
			if (head == NULL || head->next == NULL) {
				return false;
			}
			ListNode *h1 = head;
			ListNode *h2 = head->next->next;
			while (h1 != NULL && h2 != NULL) {
				if (h1 == h2) {
					return true;
				}

				h1 = h1->next;
				if (h2->next == NULL) {
					break;
				}
				h2 = h2->next->next;
			}
			
			return false;
		}
};
