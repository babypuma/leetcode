/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/16
 *
 * Source : https://leetcode-cn.com/problems/minimum-window-substring/
 * Problem:	Minimum Window Substring
 *               
 */
#include <gtest/gtest.h>
#include "minimum_window_substring.h"

TEST(Solution, minWindow) {
  struct TestData {
    string str1;
    string str2;
    string sub;
  };

  TestData test_data[] = {
    {"ADOBECODEBANC", "ABC", "BANC"},
    {"a", "a", "a"},
    {"aaaaaaaaaaaabbbbbcdd", "abcdd", "abbbbbcdd"},
  };

  Solution solution;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    string sub = solution.minWindow(test_data[i].str1, test_data[i].str2);
    EXPECT_STREQ(sub.c_str(), test_data[i].sub.c_str());
  }
}

