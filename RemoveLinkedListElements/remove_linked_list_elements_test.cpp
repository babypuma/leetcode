/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/remove-linked-list-elements/
 * Problem:	Remove Linked List Elements
 *
 */
#include <gtest/gtest.h>
#include "remove_linked_list_elements.h"

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
	int a[] = {2, 6, 3, 4, 5, 6};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	node = solution_.removeElements(head, 6);
	int b[] = {1, 2, 3, 4, 5};
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(node->val, b[i]);
		node = node->next;
	}
}

