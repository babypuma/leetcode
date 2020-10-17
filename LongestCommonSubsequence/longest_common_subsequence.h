/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/17
 *
 * Source : https://leetcode-cn.com/problems/longest-common-subsequence/
 * Problem:	Longest Common Subsequence
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   int longestCommonSubsequence(string text1, string text2) {
     int m = text1.size();
     int n = text2.size();
     if (m == 0 || n == 0) {
       return 0;
     }
     vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
     for (int i = 1; i < n + 1; ++i) {
       for (int j = 1; j < m + 1; ++j) {
         if (text2[i - 1] == text1[j - 1]) {
           dp[i][j] = dp[i - 1][j - 1] + 1;
         } else {
           dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
         }
       }
     }
     return dp[n][m];
   }
};
