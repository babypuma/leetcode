/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/07
 *
 * Source : https://leetcode-cn.com/problems/largest-merge-of-two-strings/
 * Problem: Largest Merge Of Two Strings
 *               
 */
#include <gtest/gtest.h>
#include "largest_merge_of_two_strings.h"

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
    string s1;
    string s2;
    string m;
  };
  TestData test_data[] = {
    {"aaa", "aaa", "aaaaaa"},
    {"cabaa", "bcaaa", "cbcabaaaaa"},
    {"bcde", "bcdeab", "bcdebcdeab"},
    {"bcde", "bcdebcdf", "bcdebcdfbcde"},
    {"uuurruuuruuuuuuuuruuuuu", "urrrurrrrrrrruurrrurrrurrrrruu", "uuuurruuuruuuuuuuuruuuuurrrurrrrrrrruurrrurrrurrrrruu"},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.largestMerge(test_data[i].s1, test_data[i].s2).c_str(), test_data[i].m.c_str());
  }
}

