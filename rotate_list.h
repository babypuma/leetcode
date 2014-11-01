/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/rotate-list/
 * Problem:	Rotate List
 * Description: 
 *	Given a list, rotate the list to the right by k places, where k is non-negative.  
 *	For example:
 *	Given 1->2->3->4->5->NULL and k = 2,
 *	return 4->5->1->2->3->NULL.
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
		ListNode *rotateRight(ListNode *head, int k) {
			size_t length = size(head);
			if (length == 0) {
				return head;
			}
			k = k % length;
			ListNode *node = head;
			while (node != NULL && k > 0) {
				node = node->next;
				k--;
			}
			if (node == NULL) {
				return head;
			}
			
			ListNode *tail = head;
			while (node->next != NULL) {
				node = node->next;
				tail = tail->next;
			}

			node->next = head;
			head = tail->next;
			tail->next = NULL;
			
			return head;
		}

		size_t size(ListNode *head) {
			size_t length = 0;
			while (head != NULL) {
				head = head->next;
				length++;
			}
			
			return length;
		}
};
