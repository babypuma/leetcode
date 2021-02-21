/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/21
 *
 * Source : https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations/
 * Problem: Maximum Score from Performing Multiplication Operations
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maximumScore(vector<int>& nums, vector<int>& multipliers) {
     int n = nums.size();
     int m = multipliers.size();
     vector<vector<int> > dp(m + 1, vector<int>(m + 1));
     int ans = INT_MIN;
     for (int k = 1; k <= m ; ++k) {
       for (int i = 0; i <= k; ++i) {
         int j = k - i;
         if (i == 0) {
           dp[i][j] = dp[i][j - 1] + nums[n - j] * multipliers[k - 1];
         } else if (i == k) {
           dp[i][j] = dp[i - 1][j] + nums[i - 1] * multipliers[k - 1];
         } else {
           dp[i][j] = std::max(dp[i - 1][j] + nums[i - 1] * multipliers[k - 1], dp[i][j - 1] + nums[n - j] * multipliers[k - 1]);
         }
         if (k == m) {
           ans = std::max(ans, dp[i][j]);
         }
       }
     }
     return ans;
   }
};
