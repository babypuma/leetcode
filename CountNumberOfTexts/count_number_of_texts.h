/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/12
 *
 * Source : https://leetcode.cn/contest/weekly-contest-292/problems/count-number-of-texts/
 * Problem:	Count Number of Texts
 *
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int countTexts(string pressedKeys) {
     string& p = pressedKeys;
     vector<int64_t> dp(p.size());
     dp[0] = 1;
     for (size_t i = 1; i < p.size(); ++i) {
       dp[i] = dp[i - 1];
       if (p[i] == p[i - 1]) {
         dp[i] += i >= 2 ? dp[i - 2] : 1;
         if (i >= 2 && p[i - 1] == p[i - 2]) {
           dp[i] += i >= 3 ? dp[i - 3] : 1;
           if ((p[i] == '7' || p[i] == '9') && i >= 3 && p[i - 3] == p[i - 2]) {
             dp[i] += i >= 4 ? dp[i - 4] : 1;
           }
         }
       }
       dp[i] %= MOD;
     }
     return dp.back();
   }
   
 private:
   static const int MOD = static_cast<int>(1e9) + 7;
};
