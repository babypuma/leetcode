/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/15
 *
 * Source : https://leetcode-cn.com/problems/max-consecutive-ones/
 * Problem: Max Consecutive Ones
 *               
 */
#include <gtest/gtest.h>
#include "max_consecutive_ones.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1, 1, 0, 1, 1, 1};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.findMaxConsecutiveOnes(nums), 3);
}

