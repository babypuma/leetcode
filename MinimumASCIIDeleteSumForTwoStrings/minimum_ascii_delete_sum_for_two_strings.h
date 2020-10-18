/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/18
 *
 * Source : https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/
 * Problem:	Minimum ASCII Delete Sum for Two Strings
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   int minimumDeleteSum(string s1, string s2) {
     int m = s1.size();
     int n = s2.size();
     vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
     for (int i = 1; i < m + 1; ++i) {
       dp[0][i] = dp[0][i - 1] + static_cast<int>(s1[i - 1]);
     }
     for (int i = 1; i < n + 1; ++i) {
       dp[i][0] = dp[i - 1][0] + static_cast<int>(s2[i - 1]);
     }

     for (int i = 1; i < n + 1; ++i) {
       for (int j = 1; j < m + 1; ++j) {
         if (s2[i - 1] == s1[j - 1]) {
           dp[i][j] = dp[i - 1][j - 1];
         } else {
           dp[i][j] = std::min(dp[i - 1][j] + static_cast<int>(s2[i - 1]),
                               dp[i][j - 1] + static_cast<int>(s1[j - 1]));
         }
       }
     }
     return dp[n][m];
   }
};
