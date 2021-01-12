/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/12
 *
 * Source : https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * Problem: Single Element in a Sorted Array
 *               
 */
#include <gtest/gtest.h>
#include "single_element_in_a_sorted_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,1,2,3,3,4,4,8,8};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.singleNonDuplicate(vec), 2);
}

TEST_F(SolutionTest, case2) {
  int a[] = {3,3,7,7,10,11,11};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.singleNonDuplicate(vec), 10);
}

