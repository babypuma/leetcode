/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/28
 *
 * Source : https://leetcode-cn.com/problems/number-of-different-integers-in-a-string/
 * Problem: Number of Different Integers in a String
 *               
 */
#include <gtest/gtest.h>
#include "number_of_different_integers_in_a_string.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  EXPECT_EQ(solution_.numDifferentIntegers("a123bc34d8ef34"), 3);
}

