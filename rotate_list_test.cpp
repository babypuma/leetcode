/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/rotate-list/
 * Problem:	Rotate List
 *
 */
#include <gtest/gtest.h>
#include "rotate_list.h"

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
	int a[] = {2, 3, 4, 5};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	node = solution_.rotateRight(head, 2);
	int b[] = {4, 5, 1, 2, 3};
	size_t j = 0;
	while (node != NULL) {
		EXPECT_EQ(b[j], node->val);
		node = node->next;
		j++;
	}
	EXPECT_EQ(j, sizeof(b)/sizeof(int));
}

TEST_F(SolutionTest, case2) {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);

	ListNode *node = solution_.rotateRight(head, 3);
	int b[] = {2, 1};
	size_t j = 0;
	while (node != NULL) {
		EXPECT_EQ(b[j], node->val);
		node = node->next;
		j++;
	}
	EXPECT_EQ(j, sizeof(b)/sizeof(int));
}

