#include <stdio.h>

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			ListNode *front = head;
			for (int i = 0; i < n; i++) {
				front = front->next;
			}

			if (front == NULL) {
				return head->next;
			}

			ListNode *back = head;
			while (front->next != NULL) {
				front = front->next;
				back = back->next;
			}
			back->next = back->next->next;

			return head;
		}
};
