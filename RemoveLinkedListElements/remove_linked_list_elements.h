/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/remove-linked-list-elements/
 * Problem:	Remove Linked List Elements
 * Description: 
 *	Remove all elements from a linked list of integers that have value val.
 *
 * 	Example
 * 	Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 *	Return: 1 --> 2 --> 3 --> 4 --> 5
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
		ListNode* removeElements(ListNode* head, int val) {
			ListNode *p = new ListNode(0);
			p->next = head;
			ListNode *node = p;
			while (node->next != NULL) {
				if (node->next->val == val) {
					ListNode *tmp = node->next;
					node->next = tmp->next;
					delete tmp;
				}
				else {
					node = node->next;
				}
			}
			
			node = p->next;
			delete p;

			return node;
		}
};
