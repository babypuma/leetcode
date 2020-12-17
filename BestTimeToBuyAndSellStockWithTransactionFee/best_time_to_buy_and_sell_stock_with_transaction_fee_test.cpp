/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * Problem: Best Time to Buy and Sell Stock with Transaction Fee
 *               
 */
#include <gtest/gtest.h>
#include "best_time_to_buy_and_sell_stock_with_transaction_fee.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1, 3, 2, 8, 4, 9};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxProfit(vec, 2), 8);
}

TEST_F(SolutionTest, case2) {
  int a[] = {9,8,7,1,2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxProfit(vec, 3), 0);
}

