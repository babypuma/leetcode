/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/
 * Problem: Latest Time by Replacing Hidden Digits
 *               
 */
#include <gtest/gtest.h>
#include "latest_time_by_replacing_hidden_digits.h"

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
    string n1;
    string n2;
  };
  TestData test_data[] = {
    {"2?:?0", "23:50"},
    {"0?:3?", "09:39"},
    {"1?:22", "19:22"},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.maximumTime(test_data[i].n1).c_str(), test_data[i].n2.c_str());
  }
}

