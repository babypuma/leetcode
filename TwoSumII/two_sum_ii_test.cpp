/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * Problem: Two Sum II - Input array is sorted
 *               
 */
#include <gtest/gtest.h>
#include "two_sum_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,7,11,15};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> res = solution_.twoSum(vec, 9);
  EXPECT_EQ(res.size(), 2);
  EXPECT_EQ(res[0], 1);
  EXPECT_EQ(res[1], 2);
}

