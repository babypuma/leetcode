/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/29
 *
 * Source : https://leetcode.cn/contest/weekly-contest-295/problems/apply-discount-to-prices/
 * Problem:	Apply Discount to Prices
 *
 */
#include <gtest/gtest.h>
#include "apply_discount_to_prices.h"

TEST(Solution, testcase) {
  struct TestCase {
    string str1;
    int dis;
    string str2;
  };
  TestCase test_case[] = {
    {"there are $1 $2 and 5$ candies in the shop", 50, "there are $0.50 $1.00 and 5$ candies in the shop"},
    {"1 2 $3 4 $5 $6 7 8$ $9 $10$", 100, "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"},
    {"$76111 ab $6 $", 48, "$39577.72 ab $3.12 $"},
  };

  Solution solution;
  for (size_t i = 0; i < sizeof(test_case)/sizeof(test_case[0]); ++i) {
    EXPECT_STREQ(solution.discountPrices(test_case[i].str1, test_case[i].dis).c_str(), test_case[i].str2.c_str());
  }
}

