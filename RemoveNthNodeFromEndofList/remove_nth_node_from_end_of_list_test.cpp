#include <gtest/gtest.h>
#include "remove_nth_node_from_end_of_list.h"

using std::set;

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
	ListNode *node;
	for (int i = 5; i > 1; i--) {
		node = new ListNode(i);
		node->next = head->next;
		head->next = node;
	}
	node = solution_.removeNthFromEnd(head, 2);
	int a[] = {1, 2, 3, 5};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		EXPECT_TRUE(node != NULL);
		EXPECT_EQ(node->val, a[i]);
		node = node->next;
	}
}

TEST_F(SolutionTest, case2) {
	ListNode *head = new ListNode(1);
	ListNode *node = solution_.removeNthFromEnd(head, 1);
	EXPECT_TRUE(node == NULL);
}

TEST_F(SolutionTest, case3) {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	ListNode *node;
	node = solution_.removeNthFromEnd(head, 2);
	ASSERT_TRUE(node != NULL);
	EXPECT_TRUE(node->next == NULL);
	EXPECT_TRUE(node->val == 2);
}

