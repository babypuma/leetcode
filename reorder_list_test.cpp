/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/31
 *
 * Source : https://oj.leetcode.com/problems/reorder-list/
 * Problem:	Reorder List
 *
 */
#include <gtest/gtest.h>
#include "reorder_list.h"

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
	ListNode *node = head;
	int a[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}
	ASSERT_EQ(10, (int)solution_.length(head));
}

TEST_F(SolutionTest, case2) {
	ListNode *head = new ListNode(1);
	ListNode *node = head;
	int a[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	node = solution_.reverse(head);
	size_t i = 0;
	while (node != NULL) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
		i++;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

TEST_F(SolutionTest, case3) {
	ListNode *head = new ListNode(1);
	ListNode *node = head;
	int a[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}
	ASSERT_EQ(10, (int)solution_.length(head));

	int b[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
	solution_.reorderList(head);
	ASSERT_EQ(10, (int)solution_.length(head));

	node = head;
	size_t i = 0;
	while (node != NULL) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
		i++;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

