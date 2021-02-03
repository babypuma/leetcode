/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/03
 *
 * Source : https://leetcode-cn.com/problems/palindrome-partitioning-iv/
 * Problem: Palindrome Partitioning IV
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   bool checkPartitioning(string s) {
     int sz = s.size();
     vector<vector<bool> > dp(sz, vector<bool>(sz, false));
     for (int i = 0; i < sz; ++i) {
       dp[i][i] = true;
     }
     for (int i = sz - 2; i >= 0; --i) {
       for (int j = i + 1; j < sz; ++j) {
         if (j == i + 1) {
           dp[i][j] = (s[i] == s[j]);
         } else {
           dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
         }
       }
     }
     for (int i = 0; i < sz - 2; ++i) {
       if (!dp[0][i]) {
         continue;
       }
       for (int j = i + 1; j < sz - 1; ++j) {
         if (dp[i + 1][j] && dp[j + 1][sz - 1]) {
           return true;
         }
       }
     }

     return false;
   }
};
