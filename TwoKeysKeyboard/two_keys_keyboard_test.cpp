/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/27
 *
 * Source : https://leetcode-cn.com/problems/2-keys-keyboard/
 * Problem:	2 Keys Keyboard
 *
 */
#include <gtest/gtest.h>
#include "two_keys_keyboard.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, minSteps) {
  EXPECT_EQ(solution_.minSteps(3), 3);
}

