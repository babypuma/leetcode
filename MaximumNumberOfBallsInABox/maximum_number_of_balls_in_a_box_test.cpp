/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/31
 *
 * Source : https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/
 * Problem: Maximum Number of Balls in a Box
 *               
 */
#include <gtest/gtest.h>
#include "maximum_number_of_balls_in_a_box.h"

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
    int low;
    int high;
    int count;
  };
  TestData test_data[] = {
    {1, 10, 2},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.countBalls(test_data[i].low, test_data[i].high), test_data[i].count);
  }
}

