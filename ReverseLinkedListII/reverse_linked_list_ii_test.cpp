/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/05
 *
 * Source : https://oj.leetcode.com/problems/reverse-linked-list-ii/
 * Problem:	Reverse Linked List II
 *
 */
#include <gtest/gtest.h>
#include "reverse_linked_list_ii.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	ListNode *head = new ListNode(1);
	int a[] = {2, 3, 4, 5};
	ListNode *node = head;
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	head = solution_.reverseBetween(head, 2, 4);
	int b[] = {1, 4, 3, 2, 5};
	size_t i = 0; 
	for (node = head; node != NULL && i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

TEST_F(SolutionTest, case2) {
	ListNode *head = new ListNode(1);
	int a[] = {2, 3, 4, 5};
	ListNode *node = head;
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	head = solution_.reverseBetween(head, 1, 4);
	int b[] = {4, 3, 2, 1, 5};
	size_t i = 0; 
	for (node = head; node != NULL && i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

TEST_F(SolutionTest, case3) {
	ListNode *head = new ListNode(5);
	head = solution_.reverseBetween(head, 1, 1);
	EXPECT_TRUE(head->next == NULL);
	EXPECT_EQ(head->val, 5);
}

