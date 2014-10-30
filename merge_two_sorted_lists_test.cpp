/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/merge-two-sorted-lists/
 * Problem:	Merge Two Sorted Lists
 *
 */
#include <gtest/gtest.h>
#include "merge_two_sorted_lists.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	ListNode *node;
	ListNode *h1 = new ListNode(1);
	int a[] = {9, 7, 5, 3};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node = new ListNode(a[i]);
		node->next = h1->next;
		h1->next = node;
	}

	ListNode *h2 = new ListNode(2);
	int b[] = {10, 8, 6, 4};
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		node = new ListNode(b[i]);
		node->next = h2->next;
		h2->next = node;
	}

	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	node = solution_.mergeTwoLists(h1, h2);
	size_t j = 0;
	while (node != NULL) {
		EXPECT_EQ(c[j], node->val);
		node = node->next;
		j++;
	}
	EXPECT_EQ(j, sizeof(c)/sizeof(int));
}

