/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/17
 *
 * Source : https://leetcode-cn.com/problems/edit-distance/
 * Problem:	Edit Distance
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   int minDistance(string word1, string word2) {
     int m = word1.size();
     int n = word2.size();
     if (m == 0 || n == 0) {
       return m + n;
     }
     vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
     for (int i = 1; i < n + 1; ++i) {
       dp[i][0] = i;
     }
     for (int j = 1; j < m + 1; ++j) {
       dp[0][j] = j;
     }
     for (int i = 1; i < n + 1; ++i) {
       for (int j = 1; j < m + 1; ++j) {
         if (word2[i - 1] == word1[j - 1]) {
           dp[i][j] = dp[i - 1][j - 1];
         } else {
           dp[i][j] = dp[i - 1][j - 1] + 1;
         }
         dp[i][j] = std::min(dp[i][j], std::min(dp[i - 1][j], dp[i][j - 1]) + 1);
       }
     }
     return dp[n][m];
   }
};
