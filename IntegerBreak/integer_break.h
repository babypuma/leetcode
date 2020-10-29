/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/integer-break/
 * Problem:	Integer Break
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int integerBreak(int n) {
     vector<int> dp(n + 1);
     dp[0] = 0;
     dp[1] = 1;
     for (int i = 2; i < n + 1; ++i) {
       dp[i] = i - 1;
       for (int j = 1; j < i - 1; ++j) {
         dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
       }
     }
     return dp[n];
   }
};
