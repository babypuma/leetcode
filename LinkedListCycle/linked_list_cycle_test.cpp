/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/linked-list-cycle/
 * Problem:	Linked List Cycle
 *
 */
#include <gtest/gtest.h>
#include "linked_list_cycle.h"

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
	int a[100] = {0};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}
	node->next = head->next;
	EXPECT_TRUE(solution_.hasCycle(head));
}

TEST_F(SolutionTest, case2) {
	ListNode *head = new ListNode(0);
	ListNode *node = head;
	int a[100] = {0};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}
	EXPECT_FALSE(solution_.hasCycle(head));
}

