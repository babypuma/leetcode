/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/07
 *
 * Source : https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated/
 * Problem: check_if_array_is_sorted_and_rotated.h
 *               
 */
#include <gtest/gtest.h>
#include "check_if_array_is_sorted_and_rotated.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,1,3,4};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_FALSE(solution_.check(nums));
}

TEST_F(SolutionTest, case2) {
  int a[] = {6,10,6};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.check(nums));
}

