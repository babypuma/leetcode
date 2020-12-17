/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * Problem: Best Time to Buy and Sell Stock with Transaction Fee
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxProfit(vector<int>& prices, int fee) {
     // dp[i][0]表示第i天是空仓，dp[i][1]表示第i天持有股票
     vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
     dp[0][0] = 0;
     dp[0][1] = 0 - prices[0];
     for (size_t i = 1; i < dp.size(); ++i) {
       dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
       dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
     }
     return dp[dp.size() - 1][0];
   }
};
