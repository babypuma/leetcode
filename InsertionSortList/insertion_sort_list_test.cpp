/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/insertion-sort-list/
 * Problem:	Insertion Sort List
 *
 */
#include <gtest/gtest.h>
#include "insertion_sort_list.h"

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
	ListNode *head = new ListNode(1);
	int a[] = {9, 7, 5, 8, 10, 3, 2, 4, 6};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node = new ListNode(a[i]);
		node->next = head->next;
		head->next = node;
	}

	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	node = solution_.insertionSortList(head);
	size_t i = 0;
	while (node != NULL) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
		i++;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

