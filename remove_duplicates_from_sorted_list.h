/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Problem:	Remove Duplicates from Sorted List
 * Description: 
 *	Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 *	For example,
 *	Given 1->1->2, return 1->2.
 *	Given 1->1->2->3->3, return 1->2->3.
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
		ListNode *deleteDuplicates(ListNode *head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}

			ListNode *node = head;
			ListNode *temp;
			while (node->next != NULL) {
				if (node->val == node->next->val) {
					temp = node->next;
					node->next = temp->next;
					delete temp;
				}
				else {
					node = node->next;
					if (node == NULL) {
						break;
					}
				}
			}

			return head;
		}
};
