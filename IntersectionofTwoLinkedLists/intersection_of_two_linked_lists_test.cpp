/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/13
 *
 * Source : https://oj.leetcode.com/problems/intersection-of-two-linked-lists
 * Problem:	Intersection of Two Linked Lists
 *
 */
#include <gtest/gtest.h>
#include "intersection_of_two_linked_lists.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	ListNode *headA = new ListNode(0);
	ListNode *node = headA;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	ListNode *headB = headA;
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == headA);
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == headB);
}

TEST_F(SolutionTest, case2) {
	ListNode *headA = new ListNode(0);
	ListNode *node = headA;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}

	ListNode *headB = new ListNode(100);
	node = headB;
	int b[5] = {200, 300, 400, 500, 600};
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		node->next = new ListNode(b[i]);
		node = node->next;
	}
	node->next = headA;
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == headA);
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) != headB);
}

TEST_F(SolutionTest, case3) {
	ListNode *headC = new ListNode(0);
	ListNode *node = headC;
	int c[5] = {200, 400, 600, 800, 1000};
	for (size_t i = 0; i < sizeof(c)/sizeof(int); i++) {
		node->next = new ListNode(c[i]);
		node = node->next;
	}

	ListNode *headA = new ListNode(0);
	node = headA;
	int a[5] = {1, 3, 5, 7, 9};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node->next = new ListNode(a[i]);
		node = node->next;
	}
	node->next = headC;

	ListNode *headB = new ListNode(0);
	node = headB;
	int b[5] = {2, 4, 6, 8, 10};
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		node->next = new ListNode(b[i]);
		node = node->next;
	}
	node->next = headC;

	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == headC);
}

TEST_F(SolutionTest, case4) {
	ListNode *headA = NULL;
	ListNode *headB = NULL;
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == NULL);
}

TEST_F(SolutionTest, case5) {
	ListNode *headA = new ListNode(0);
	ListNode *headB = headA;
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == headA);
	EXPECT_TRUE(solution_.getIntersectionNode(headA, headB) == headB);
}

