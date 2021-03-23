/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/23
 *
 * Source : https://leetcode-cn.com/problems/maximum-ascending-subarray-sum/
 * Problem: Maximum Ascending Subarray Sum
 *               
 */
#include <gtest/gtest.h>
#include "maximum_ascending_subarray_sum.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {10,20,30,5,10,50};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxAscendingSum(vec), 65);
}

