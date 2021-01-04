/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 * Update : 2021/01/04
 *
 * Source : https://leetcode-cn.com/problems/partition-list/
 * Problem:	Partition List
 *
 */
#include <gtest/gtest.h>
#include "partition_list.h"

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
  int a[] = {4, 3, 2, 5, 2};
  for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
    node->next = new ListNode(a[i]);
    node = node->next;
  }

  node = solution_.partition(head, 3);
  int b[] = {1, 2, 2, 4, 3, 5};
  size_t j = 0;
  while (node != NULL) {
    EXPECT_EQ(b[j], node->val);
    node = node->next;
    j++;
  }
  EXPECT_EQ(j, sizeof(b)/sizeof(int));
}

