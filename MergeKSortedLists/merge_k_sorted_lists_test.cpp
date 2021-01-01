/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/01
 *
 * Source : https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * Problem:	Merge K Sorted Lists
 *
 */
#include <gtest/gtest.h>
#include "merge_k_sorted_lists.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<ListNode*> lists;
  ListNode *node;
  ListNode *h1 = new ListNode(1);
  int a[] = {5,4};
  for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
    node = new ListNode(a[i]);
    node->next = h1->next;
    h1->next = node;
  }
  lists.push_back(h1);

  ListNode *h2 = new ListNode(1);
  int b[] = {4,3};
  for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
    node = new ListNode(b[i]);
    node->next = h2->next;
    h2->next = node;
  }
  lists.push_back(h2);

  ListNode *h3 = new ListNode(2);
  h3->next = new ListNode(6);
  lists.push_back(h3);

  int c[] = {1,1,2,3,4,4,5,6};
  node = solution_.mergeKLists(lists);
  size_t j = 0;
  while (node != NULL) {
    EXPECT_EQ(c[j], node->val);
    node = node->next;
    j++;
  }
  EXPECT_EQ(j, sizeof(c)/sizeof(int));
}

