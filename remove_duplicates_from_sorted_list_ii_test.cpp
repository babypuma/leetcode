/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/19
 *
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Problem:	Remove Duplicates from Sorted List II
 *
 */
#include <gtest/gtest.h>
#include "remove_duplicates_from_sorted_list_ii.h"

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
	int a[] = {2, 3, 3, 4, 4, 5};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	int b[] = {1, 2, 5};
	node = solution_.deleteDuplicates(head);
	size_t i = 0;
	while (node != NULL) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
		i++;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

TEST_F(SolutionTest, case2) {
	ListNode *head = new ListNode(1);
	ListNode *node = head;
	int a[] = {1, 1, 2, 3};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	int b[] = {2, 3};
	node = solution_.deleteDuplicates(head);
	size_t i = 0;
	while (node != NULL) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
		i++;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

