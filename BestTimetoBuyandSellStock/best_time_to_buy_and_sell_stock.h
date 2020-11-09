/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Update : 2020/10/17,2020/11/09
 *
 * Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * Problem:	Best Time to Buy and Sell Stock
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxProfit(vector<int> &prices) {
     if (prices.empty()) {
       return 0;
     }
     int min = prices[0];
     int ans = 0;
     for (int i = 1; i < prices.size(); ++i) {
       ans = std::max(ans, prices[i] - min);
       min = std::min(min, prices[i]);
     }
     return ans;
   }
};

