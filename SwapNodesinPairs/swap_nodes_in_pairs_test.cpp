#include <gtest/gtest.h>
#include "swap_nodes_in_pairs.h"

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
	int a[] = {4, 3, 2};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		node = new ListNode(a[i]);
		node->next = head->next;
		head->next = node;
	}

	node = solution_.swapPairs(head);
	int b[] = {2, 1, 4, 3};
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		EXPECT_TRUE(node != NULL);
		EXPECT_EQ(node->val, b[i]);
		node = node->next;
	}
}

