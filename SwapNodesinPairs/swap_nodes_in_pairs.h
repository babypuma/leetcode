#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *swapPairs(ListNode *head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}

			ListNode *prev = NULL;
			ListNode *first = head->next;
			ListNode *second = head;
			head = first;
			while (first != NULL) {
				second->next = first->next;
				first->next = second;
				if (prev != NULL) {
					prev->next = first;
				}

				prev = second;
				second = prev->next;
				if (second == NULL) {
					break;
				}
				first = second->next;
			}

			return head;
		}
};
