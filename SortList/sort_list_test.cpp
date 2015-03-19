/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/sort-list/
 * Problem:	Sort List
 *
 */
#include <gtest/gtest.h>
#include "sort_list.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	ListNode *head = new ListNode(9);
	ListNode *node = head;
	int a[] = {8, 2, 3, 1, 7, 5, 6, 10, 4};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	node = solution_.sortList(head);
	size_t j = 0;
	while (node != NULL) {
		EXPECT_EQ(b[j], node->val);
		node = node->next;
		j++;
	}
	EXPECT_EQ(j, sizeof(b)/sizeof(int));
}

