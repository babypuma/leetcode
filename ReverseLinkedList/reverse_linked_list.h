/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/reverse-linked-list/
 * Problem:	Reverse Linked List
 * Description: 
 *	Reverse a singly linked list.
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
		ListNode* reverseList(ListNode* head) {
			ListNode* p = new ListNode(0);
			ListNode* node;
			while (head != NULL) {
				node = head;
				head = head->next;
				node->next = p->next;
				p->next = node;
			}

			node = p->next;
			delete p;
			return node;
		}
};
