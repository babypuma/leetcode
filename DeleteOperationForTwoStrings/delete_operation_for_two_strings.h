/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/14
 *
 * Source : https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 * Problem:	Delete Operation for Two Strings
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
     vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
     for (int i = 1; i < m + 1; ++i) {
       for (size_t j = 1; j < n + 1; ++j) {
         if (word1[i - 1] == word2[j - 1]) {
           dp[i][j] = dp[i - 1][j - 1] + 1;
         } else {
           dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
         }
       }
     }
     return m + n - 2 * dp[m][n];
   }
};
