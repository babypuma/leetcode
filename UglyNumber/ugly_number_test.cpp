/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/ugly-number/
 * Problem: Ugly Number
 *               
 */
#include <gtest/gtest.h>
#include "ugly_number.h"

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
    bool u;
  };
  TestData test_data[] = {
    {6, true},
    {8, true},
    {14, false},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.isUgly(test_data[i].n) == test_data[i].u);
  }
}

