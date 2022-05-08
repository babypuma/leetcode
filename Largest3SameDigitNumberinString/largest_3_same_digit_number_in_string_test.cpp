/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/08
 *
 * Source : https://leetcode-cn.com/contest/weekly-contest-292/problems/largest-3-same-digit-number-in-string/
 * Problem: Largest 3-Same-Digit Number in String
 *
 */
#include <gtest/gtest.h>
#include "largest_3_same_digit_number_in_string.h"

TEST(Solution, case1) {
  Solution s;
  EXPECT_STREQ(s.largestGoodInteger("6777133339").c_str(), "777");
}

TEST(Solution, case2) {
  Solution s;
  EXPECT_STREQ(s.largestGoodInteger("222").c_str(), "222");
}

TEST(Solution, case3) {
  Solution s;
  EXPECT_STREQ(s.largestGoodInteger("").c_str(), "");
}

