/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/insertion-sort-list/
 * Problem:	Insertion Sort List
 * Description: 
 *	Sort a linked list using insertion sort.
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
		ListNode *insertionSortList(ListNode *head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}
			ListNode *new_head = head;
			head = head->next;
			new_head->next = NULL; 
			ListNode *node;
			ListNode *curr;
			while (head != NULL) {
				node = head;
				head = head->next;
				if (node->val < new_head->val) {
					node->next = new_head;
					new_head = node;
					continue;
				}

				curr = new_head;
				while (curr->next != NULL && curr->next->val < node->val) {
					curr = curr->next;
				}
				node->next = curr->next;
				curr->next = node;
			}

			return new_head;
		}
};
