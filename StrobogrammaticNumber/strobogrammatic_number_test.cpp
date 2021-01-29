/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/strobogrammatic-number/
 * Problem: Strobogrammatic Number
 *               
 */
#include <gtest/gtest.h>
#include "strobogrammatic_number.h"

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
    string s;
    bool y;
  };
  TestData test_data[] = {
    {"69", true},
    {"88", true},
    {"962", false},
    {"1", true},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.isStrobogrammatic(test_data[i].s) == test_data[i].y);
  }
}

