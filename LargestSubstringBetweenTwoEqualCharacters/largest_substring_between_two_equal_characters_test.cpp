/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters/
 * Problem: Largest Substring Between Two Equal Characters
 *
 */
#include <gtest/gtest.h>
#include "largest_substring_between_two_equal_characters.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, maxLengthBetweenEqualCharacters) {
  struct TestData {
    string str;
    int len;
  };
  TestData test_data[] = {
    {"aa", 0},
    {"abca", 2},
    {"cbzxy", -1},
    {"cabbac", 4},
  };
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters(test_data[i].str), test_data[i].len);
  }
}

