/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem: Median of Two Sorted Arrays
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int coinChange(vector<int>& coins, int amount) {
     std::sort(coins.begin(), coins.end());
     vector<int> dp(amount + 1, INT_MAX);
     dp[0] = 0;
     for (int i = 1; i < amount + 1; ++i) {
       for (auto& c : coins) {
         if (i - c >= 0) {
           if (dp[i - c] != INT_MAX && dp[i] > dp[i - c] + 1) {
             dp[i] = dp[i - c] + 1;
           }
         } else {
           break;
         }
       }
     }
     return dp[amount] == INT_MAX ? -1 : dp[amount];
   }
};
