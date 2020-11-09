/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 * Update : 2020/11/09
 *
 * Source : https://leetcode-cn.com/problems/merge-sorted-array/
 * Problem:	Merge Sorted Array
 *
 */
#include <gtest/gtest.h>
#include "merge_sorted_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1, 3, 5, 7, 0, 0, 0, 0};
  int b[] = {2, 4, 6, 8};
  int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> vb(b, b + sizeof(b)/sizeof(b[0]));
  solution_.merge(va, 4, vb, 4);
  for (size_t i = 0; i < sizeof(c)/sizeof(c[0]); i++) {
    EXPECT_EQ(c[i], va[i]);
  }
}

