/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/27
 *
 * Source : https://leetcode-cn.com/problems/power-of-three/
 * Problem: Power of Three
 *               
 */
#include <gtest/gtest.h>
#include "power_of_three.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  struct TestData {
    int n;
    bool y;
  };
  TestData test_data[] = {
    {27, true},
    {0, false},
    {9, true},
    {45, false},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.isPowerOfThree(test_data[i].n) == test_data[i].y);
  }
}

