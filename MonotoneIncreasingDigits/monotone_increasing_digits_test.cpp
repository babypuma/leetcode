/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/monotone-increasing-digits/
 * Problem: Monotone Increasing Digits
 *               
 */
#include <gtest/gtest.h>
#include "monotone_increasing_digits.h"

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
    int n1;
    int n2;
  };
  TestData test_data[] = {
    {10, 9},
    {1234, 1234},
    {332, 299},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.monotoneIncreasingDigits(test_data[i].n1), test_data[i].n2);
  }
}

