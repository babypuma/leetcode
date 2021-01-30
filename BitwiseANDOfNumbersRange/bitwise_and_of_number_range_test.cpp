/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/30
 *
 * Source : https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 * Problem: Bitwise AND of Numbers Range
 *               
 */
#include <gtest/gtest.h>
#include "bitwise_and_of_number_range.h"

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
    int m;
    int n;
    int res;
  };
  TestData test_data[] = {
    {5, 7, 4},
    {0, 1, 0},
    {0, 0, 0},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.rangeBitwiseAnd(test_data[i].m, test_data[i].n), test_data[i].res);
  }
}

