/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/04
 *
 * Source : https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 * Problem:	Find the Longest Substring Containing Vowels in Even Counts
 *
 */
#include <gtest/gtest.h>
#include "find_the_longest_substring_containing_vowels_in_even_counts.h"

TEST(NumArray, findTheLongestSubstring) {
  struct TestData {
    string str;
    int len;
  };
  TestData test_data[] = {
    {"eleetminicoworoep", 13},
    {"leetcodeisgreat", 5},
    {"bcbcbc", 6},
  };

  Solution solution;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution.findTheLongestSubstring(test_data[i].str), test_data[i].len);
  }
}

