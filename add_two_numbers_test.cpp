#include <gtest/gtest.h>
#include "add_two_numbers.h"

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

	size_t i;
	int val1[] = {3, 4};
	ListNode l1(2);
	for (i = 0; i < sizeof(val1)/sizeof(int); i++) {
		node = new ListNode(val1[i]);
		node->next = l1.next;
		l1.next = node;
	}

	int val2[] = {4, 6};
	ListNode l2(5);
	for (i = 0; i < sizeof(val2)/sizeof(int); i++) {
		node = new ListNode(val2[i]);
		node->next = l2.next;
		l2.next = node;
	}

	int val3[] = {7, 0, 8};
	node = solution_.addTwoNumbers(&l1, &l2);
	for (i = 0; i < sizeof(val3)/sizeof(int); i++) {
		EXPECT_EQ(node->val, val3[i]);
		node = node->next;
	}
}

TEST_F(SolutionTest, case2) {
	ListNode *node;

	ListNode l1(5);
	ListNode l2(5);

	int val3[] = {0, 1};
	node = solution_.addTwoNumbers(&l1, &l2);
	for (size_t i = 0; i < sizeof(val3)/sizeof(int); i++) {
		EXPECT_EQ(node->val, val3[i]);
		node = node->next;
	}
}

