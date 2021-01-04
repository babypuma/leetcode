/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/04
 *
 * Source : https://leetcode-cn.com/problems/fibonacci-number/
 * Problem: Fibonacci Number
 *               
 */
#include <gtest/gtest.h>
#include "fibonacci_number.h"

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
    int fib;
  };
  TestData test_data[] = {
    {2, 1},
    {3, 2},
    {4, 3},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.fib(test_data[i].n), test_data[i].fib);
  }
}

