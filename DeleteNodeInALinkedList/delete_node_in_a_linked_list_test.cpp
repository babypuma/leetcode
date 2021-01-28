/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * Problem: Delete Node in a Linked List
 *               
 */
#include <gtest/gtest.h>
#include "delete_node_in_a_linked_list.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  ListNode head(4);
  head.next = new ListNode(5);
  head.next->next = new ListNode(1);
  head.next->next->next = new ListNode(9);
  solution_.deleteNode(head.next->next);
  int a[] = {4,5,9};
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    EXPECT_EQ(head.val, 4);
    EXPECT_EQ(head.next->val, 5);
    EXPECT_EQ(head.next->next->val, 9);
  }
}

