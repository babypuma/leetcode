#include <gtest/gtest.h>
#include "reverse_nodes_in_k-group.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {0, 1, 2, 3, 4, 5};
	ListNode *head = new ListNode(a[0]);
	ListNode *node;
	for (int i = sizeof(a)/sizeof(int) - 1; i > 0; i--) {
		node = new ListNode(a[i]);
		node->next = head->next;
		head->next = node;
	}

	ListNode *tail;
	for (tail = head; tail->next != NULL; tail = tail->next) {
	}

	solution_.reverse(head, tail);
	node = tail;
	for (int i = sizeof(a)/sizeof(int) - 1; i >= 0; i--) {
		ASSERT_TRUE(node != NULL);
		EXPECT_EQ(node->val, a[i]);
		node = node->next;
	}
}

TEST_F(SolutionTest, case2) {
	int a[] = {0, 1, 2};
	ListNode *head = new ListNode(a[0]);
	ListNode *node;
	for (int i = sizeof(a)/sizeof(int) - 1; i > 0; i--) {
		node = new ListNode(a[i]);
		node->next = head->next;
		head->next = node;
	}

	ListNode *tail = head->next;
	ListNode *next = tail->next;
	solution_.reverse(head, tail);
	head->next = next;
	int b[] = {1, 0, 2};
	node = tail;
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		ASSERT_TRUE(node != NULL);
		EXPECT_EQ(node->val, b[i]);
		node = node->next;
	}
}

TEST_F(SolutionTest, case3) {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *head = new ListNode(a[0]);
	ListNode *node;
	for (int i = sizeof(a)/sizeof(int) - 1; i > 0; i--) {
		node = new ListNode(a[i]);
		node->next = head->next;
		head->next = node;
	}

	int b[] = {2, 1, 4, 3, 5};
	node = solution_.reverseKGroup(head, 2);
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		ASSERT_TRUE(node != NULL);
		EXPECT_EQ(node->val, b[i]);
		node = node->next;
	}
}

TEST_F(SolutionTest, case4) {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *head = new ListNode(a[0]);
	ListNode *node;
	for (int i = sizeof(a)/sizeof(int) - 1; i > 0; i--) {
		node = new ListNode(a[i]);
		node->next = head->next;
		head->next = node;
	}

	int b[] = {3, 2, 1, 4, 5};
	node = solution_.reverseKGroup(head, 3);
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		ASSERT_TRUE(node != NULL);
		EXPECT_EQ(node->val, b[i]);
		node = node->next;
	}
}

