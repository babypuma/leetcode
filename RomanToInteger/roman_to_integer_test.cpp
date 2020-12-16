/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/roman-to-integer/
 * Problem: Roman to Integer
 *               
 */
#include <gtest/gtest.h>
#include "roman_to_integer.h"

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
    string roman;
    int num;
  };
  TestData test_data[] = {
    {"MCMXCIV", 1994},
    {"LVIII", 58},
    {"IX", 9},
    {"IV", 4},
    {"III", 3},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.romanToInt(test_data[i].roman), test_data[i].num);
  }
}

