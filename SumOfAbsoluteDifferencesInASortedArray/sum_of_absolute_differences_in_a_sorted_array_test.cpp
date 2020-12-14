/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 * Problem:	Sum of Absolute Differences in a Sorted Array
 *               
 */
#include <gtest/gtest.h>
#include "sum_of_absolute_differences_in_a_sorted_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,4,6,8,10};
  vector<int> v1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> v2 = solution_.getSumAbsoluteDifferences(v1);
  int b[] = {24,15,13,15,21};
  size_t sz = sizeof(b)/sizeof(b[0]);
  EXPECT_EQ(v2.size(), sz);
  for (size_t i = 0; i < sz; ++i) {
    EXPECT_EQ(v2[i], b[i]);
  }
}

