/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/reverse-linked-list/
 * Problem:	Reverse Linked List
 *
 */
#include <gtest/gtest.h>
#include "reverse_linked_list.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	ListNode *head = new ListNode(0);
	ListNode *node = head;
	int a[] = {1, 2, 3, 4, 5};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}
	node = solution_.reverseList(head);
	int b[] = {5, 4, 3, 2, 1, 0};
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(node->val, b[i]);
		node = node->next;
	}
}

