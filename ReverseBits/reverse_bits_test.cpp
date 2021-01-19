/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2021/01/19
 *
 * Source : https://leetcode-cn.com/problems/reverse-bits/
 * Problem: Reverse Bits
 *
 */
#include <gtest/gtest.h>
#include "reverse_bits.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  EXPECT_EQ(solution_.reverseBits(43261596), 964176192);
}

