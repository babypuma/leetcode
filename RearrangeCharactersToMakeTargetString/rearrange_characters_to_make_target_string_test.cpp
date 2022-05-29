/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/29
 *
 * Source : https://leetcode.cn/contest/weekly-contest-295/problems/rearrange-characters-to-make-target-string/
 * Problem:	Rearrange Characters to Make Target String
 *
 */
#include <gtest/gtest.h>
#include "rearrange_characters_to_make_target_string.h"

TEST(Solution, testcase) {
  struct TestCase {
    string s;
    string t;
    int cnt;
  };
  TestCase test_case[] = {
    {"ilovecodingonleetcode", "code", 2},
    {"abcba", "abc", 1},
    {"abbaccaddaeea", "aaaaa", 1},
  };

  Solution solution;
  for (size_t i = 0; i < sizeof(test_case)/sizeof(test_case[0]); ++i) {
    EXPECT_EQ(solution.rearrangeCharacters(test_case[i].s, test_case[i].t), test_case[i].cnt);
  }
}

