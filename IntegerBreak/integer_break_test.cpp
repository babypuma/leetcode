/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/integer-break/
 * Problem:	Integer Break
 *
 */
#include <gtest/gtest.h>
#include "integer_break.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, integerBreak) {
  EXPECT_EQ(solution_.integerBreak(2), 1);
  EXPECT_EQ(solution_.integerBreak(3), 2);
  EXPECT_EQ(solution_.integerBreak(10), 36);
  EXPECT_EQ(solution_.integerBreak(8), 18);
  EXPECT_EQ(solution_.integerBreak(17), 486);
}

