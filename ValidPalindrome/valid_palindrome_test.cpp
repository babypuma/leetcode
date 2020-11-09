/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 * Update : 2020/11/09
 *
 * Source : https://leetcode-cn.com/problems/valid-palindrome/
 * Problem:	Valid Palindrome 
 *
 */
#include <gtest/gtest.h>
#include "valid_palindrome.h"

TEST(SolutionTest, isPalindrome) {
  Solution solution;
  EXPECT_TRUE(solution.isPalindrome("A man, a plan, a canal: Panama"));
  EXPECT_FALSE(solution.isPalindrome("race a car"));
  EXPECT_TRUE(solution.isPalindrome(",."));
  EXPECT_FALSE(solution.isPalindrome("OP"));
}

