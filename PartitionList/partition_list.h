/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/partition-list/
 * Problem:	Partition List
 * Description: 
 *	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.  
 *	You should preserve the original relative order of the nodes in each of the two partitions.
 * 	For example,
 * 	Given 1->4->3->2->5->2 and x = 3,
 *	return 1->2->2->4->3->5.
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
		ListNode *partition(ListNode *head, int x) {
			ListNode *less_head = NULL;
			ListNode *less_tail = NULL;
			ListNode *prev = NULL;
			ListNode *node = head;
			while (node != NULL && node->val < x) {
				if (less_head == NULL) {
					less_head = node;
				} 
				less_tail = node;
				node = node->next;
			}

			if (node == NULL) {
				return less_head;
			}

			head = node;
			prev = head;
			node = head->next;
			while (node != NULL) {
				if (node->val < x) {
					if (less_tail != NULL) {
						less_tail->next = node;
					}
					else {
						less_head = node;
					} 
					less_tail = node;
					prev->next = node->next; 
				} 
				else {
					prev = node;
				}

				node = node->next;
			} 

			if (less_tail != NULL) {
				less_tail->next = head;
				return less_head;
			}

			return head;
		}
};
