/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/13
 *
 * Source : https://oj.leetcode.com/problems/intersection-of-two-linked-lists
 * Problem:	Intersection of Two Linked Lists
 * Description: 
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *					   ↘
 *						 c1 → c2 → c3
 *					   ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.  
 *
 * Notes:
 * - If the two linked lists have no intersection at all, return null.
 * - The linked lists must retain their original structure after the function returns.
 * - You may assume there are no cycles anywhere in the entire linked structure.
 * - Your code should preferably run in O(n) time and use only O(1) memory.
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
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			size_t lengthA = getLength(headA);
			if (lengthA == 0) {
				return NULL;
			}
			size_t lengthB = getLength(headB);
			if (lengthB == 0) {
				return NULL;
			}

			size_t diff;
			if (lengthA < lengthB) {
				diff = lengthB - lengthA;
				while (diff > 0) {
					headB = headB->next;
					diff--;
				}
			}
			else if (lengthA > lengthB) {
				diff = lengthA - lengthB;
				while (diff > 0) {
					headA = headA->next;
					diff--;
				}
			}

			while (headA != NULL && headB != NULL) {
				if (headA == headB) {
					return headA; 
				}
				headA = headA->next;
				headB = headB->next;
			}

			return NULL;
		}
	
	private:
		size_t getLength(ListNode *head) {
			if (head == NULL) {
				return 0;
			}
			size_t size = 1;
			while (head->next != NULL) {
				head = head->next;
				size++;
			}

			return size;
		}
};
