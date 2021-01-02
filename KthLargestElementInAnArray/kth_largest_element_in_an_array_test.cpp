/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/02
 *
 * Source : https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * Problem: Kth Largest Element in an Array
 *               
 */
#include <gtest/gtest.h>
#include "kth_largest_element_in_an_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {3,2,1,5,6,4};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.findKthLargest(vec, 2), 5);
}

TEST_F(SolutionTest, case2) {
  int a[] = {1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.findKthLargest(vec, 1), 1);
}

