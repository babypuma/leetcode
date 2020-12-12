/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 *
 * Source : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * Problem:	Longest Substring Without Repeating Characters
 *               
 */
#include <gtest/gtest.h>
#include "longest_substring_without_repeating_characters.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  EXPECT_EQ(solution_.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST_F(SolutionTest, case2) {
  EXPECT_EQ(solution_.lengthOfLongestSubstring("bbbb"), 1);
}

TEST_F(SolutionTest, case3) {
  EXPECT_EQ(solution_.lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar"), 12);
}

