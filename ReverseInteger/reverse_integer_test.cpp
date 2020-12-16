/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/reverse-integer/
 * Problem: Reverse Integer
 *               
 */
#include <gtest/gtest.h>
#include "reverse_integer.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  EXPECT_EQ(solution_.reverse(0), 0);
  EXPECT_EQ(solution_.reverse(123), 321);
  EXPECT_EQ(solution_.reverse(-2310), -132);
  EXPECT_EQ(solution_.reverse(1000), 1);
  EXPECT_EQ(solution_.reverse(1534236469), 0);
}
