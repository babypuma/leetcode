/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/11
 *
 * Source : https://leetcode-cn.com/problems/valid-palindrome-ii/
 * Problem:	Valid Palindrome II
 *               
 */
#include <gtest/gtest.h>
#include "valid_palindrome_ii.h"

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
    string str;
    bool res;
  };
  TestData test_data[] = {
    {"aba", true},
    {"abca", true},
    {"abdca", false},
  };

  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.validPalindrome(test_data[i].str) == test_data[i].res);
  }
}

