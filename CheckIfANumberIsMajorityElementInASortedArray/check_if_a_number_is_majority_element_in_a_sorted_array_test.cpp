/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/30
 *
 * Source : https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/
 * Problem: Check If a Number Is Majority Element in a Sorted Array
 *               
 */
#include <gtest/gtest.h>
#include "check_if_a_number_is_majority_element_in_a_sorted_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,4,5,5,5,5,5,6,6};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_TRUE(solution_.isMajorityElement(nums, 5));
}

