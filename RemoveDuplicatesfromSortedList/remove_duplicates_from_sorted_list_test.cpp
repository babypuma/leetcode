/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Problem:	Remove Duplicates from Sorted List
 *
 */
#include <gtest/gtest.h>
#include "remove_duplicates_from_sorted_list.h"

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
	int a[] = {2, 3, 3, 5, 6, 6, 6, 9, 10};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	int b[] = {1, 2, 3, 5, 6, 9, 10};
	node = solution_.deleteDuplicates(head);
	size_t i = 0;
	while (node != NULL) {
		EXPECT_EQ(b[i], node->val);
		node = node->next;
		i++;
	}
	EXPECT_EQ(i, sizeof(b)/sizeof(int));
}

