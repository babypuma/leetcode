struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			if (l1 == NULL) {
				return l2;
			}
			else if (l2 == NULL) {
				return l1;
			}

			int carry = 0;
			int sum = (l1->val + l2->val + carry) % 10;
			ListNode *s = new ListNode(sum);
			ListNode *tail = s;

			carry = (l1->val + l2->val + carry) / 10;
			l1 = l1->next;
			l2 = l2->next;
			while (l1 != NULL & l2 != NULL) {
				sum = (l1->val + l2->val + carry) % 10;
				tail->next = new ListNode(sum);

				carry = (l1->val + l2->val + carry) / 10;
				tail = tail->next;
				l1 = l1->next;
				l2 = l2->next;
			}

			if (l1 != NULL) {
				while (l1 != NULL) {
					sum = (l1->val + carry) % 10;
					tail->next = new ListNode(sum);

					carry = (l1->val + carry) / 10;
					tail = tail->next;
					l1 = l1->next;
				}
			}
			else if (l2 != NULL) {
				while (l2 != NULL) {
					sum = (l2->val + carry) % 10;
					tail->next = new ListNode(sum);

					carry = (l2->val + carry) / 10;
					tail = tail->next;
					l2 = l2->next;
				}
			}

			if (carry != 0) {
				tail->next = new ListNode(carry);
			}

			return s;
		}
};
