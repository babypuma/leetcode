/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/move-zeroes/
 * Problem: Move Zeroes
 *               
 */
#include <gtest/gtest.h>
#include "move_zeroes.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {0,1,0,3,12};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  solution_.moveZeroes(nums);
  int b[] = {1,3,12,0,0};
  EXPECT_EQ(nums.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < nums.size(); ++i) {
    EXPECT_EQ(nums[i], b[i]);
  }
}

