/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/02
 *
 * Source : https://leetcode-cn.com/problems/longest-valid-parentheses/
 * Problem:	Longest Valid Parentheses
 *
 */
#include <gtest/gtest.h>
#include "longest_valid_parentheses.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, longestValidParentheses) {
  EXPECT_EQ(solution_.longestValidParentheses("()"), 2);
  EXPECT_EQ(solution_.longestValidParentheses("(()"), 2);
  EXPECT_EQ(solution_.longestValidParentheses(")()())"), 4);
  EXPECT_EQ(solution_.longestValidParentheses("()(()"), 2);
}

