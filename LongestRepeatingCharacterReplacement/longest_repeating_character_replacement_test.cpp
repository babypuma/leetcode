/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/longest-repeating-character-replacement/
 * Problem: Longest Repeating Character Replacement
 *               
 */
#include <gtest/gtest.h>
#include "longest_repeating_character_replacement.h"

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
    int k;
    int n;
  };
  TestData test_data[] = {
    {"ABAB", 2, 4},
    {"AABABBA", 1, 4},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.characterReplacement(test_data[i].s, test_data[i].k), test_data[i].n);
  }
}

