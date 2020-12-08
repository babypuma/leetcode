/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/09
 *
 * Source : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Problem:	Find First and Last Position of Element in Sorted Array
 *
 */
#include <gtest/gtest.h>
#include "find_first_and_last_position_of_element_in_sorted_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {5,7,7,8,8,10};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> res = solution_.searchRange(vec, 8);
  EXPECT_EQ(res[0], 3);
  EXPECT_EQ(res[1], 4);
}

TEST_F(SolutionTest, case2) {
  int a[] = {5,7,7,8,8,10};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> res = solution_.searchRange(vec, 6);
  EXPECT_EQ(res[0], -1);
  EXPECT_EQ(res[1], -1);
}

TEST_F(SolutionTest, case3) {
  vector<int> vec;
  vector<int> res = solution_.searchRange(vec, 0);
  EXPECT_EQ(res[0], -1);
  EXPECT_EQ(res[1], -1);
}

