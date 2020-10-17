/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/17
 *
 * Source : https://leetcode-cn.com/problems/longest-common-subsequence/
 * Problem:	Longest Common Subsequence
 *
 */
#include <gtest/gtest.h>
#include "longest_common_subsequence.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, longestCommonSubsequence) {
  struct TestData {
    string str1;
    string str2;
    int lcs;
  };
  TestData test_data[] = {
    {"abcde", "ace", 3},
    {"abc", "abc", 3},
    {"abc", "def", 0},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    int lcs = solution_.longestCommonSubsequence(test_data[i].str1, test_data[i].str2);
    EXPECT_EQ(lcs, test_data[i].lcs);
  } 
}

