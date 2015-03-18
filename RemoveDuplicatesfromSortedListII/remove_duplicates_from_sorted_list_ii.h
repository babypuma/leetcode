/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/19
 *
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Problem:	Remove Duplicates from Sorted List II
 * Description: 
 *	Given a sorted linked list, delete all nodes that have duplicate numbers, 
 *	leaving only distinct numbers from the original list.
 *	For example,
 *	Given 1->2->3->3->4->4->5, return 1->2->5.
 *	Given 1->1->1->2->3, return 2->3.
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

			ListNode *dummy = new ListNode(0);
			dummy->next = head;

			ListNode *prev = dummy;
			ListNode *node = head;
			ListNode *temp;
			while (node != NULL && node->next != NULL) {
				if (node->val == node->next->val) {
					temp = node->next;
					while (temp->next != NULL && temp->next->val == node->val) {
						temp = temp->next;
					}
					prev->next = temp->next;
					temp->next = NULL;
					deleteList(node);
					node = prev->next;
				}
				else {
					prev = node;
					node = node->next;
				}
			}

			head = dummy->next;
			delete dummy;

			return head;
		}

		void deleteList(ListNode *root) {
			ListNode *node = root;
			while (node != NULL) {
				root = node->next;
				delete node;
				node = root;
			}
		}
};
