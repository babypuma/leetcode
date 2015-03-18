#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *reverseKGroup(ListNode *head, int k) {
			if (head == NULL) {
				return head;
			}

			ListNode *prev = NULL;
			ListNode *back = head;
			ListNode *front = head;
			for (int i = 1; i < k; i++) {
				front = front->next;
				if (front == NULL) {
					return head;
				}
			}
			ListNode *next = front->next;;
			head = front;

			while (true) {
				reverse(back, front);
				if (prev != NULL) {
					prev->next = front;
				}

				if (next == NULL) {
					return head;
				}
				prev = back;
				back = next;
				front = next;
				for (int i = 1; i < k; i++) {
					front = front->next;	
					if (front == NULL) {
						prev->next = back;
						return head;
					}
				}
				next = front->next;
			}

			return head;
		}

		void reverse(ListNode *&head, ListNode *&tail) {
			if (head == NULL || tail == NULL) {
				return;
			}
			ListNode *back = head;
			ListNode *front = back->next;
			ListNode *next;
			while (back != tail) {
				next = front->next;

				front->next = back;
				back = front;
				front = next;
			}
			head->next = NULL;
		}
};
