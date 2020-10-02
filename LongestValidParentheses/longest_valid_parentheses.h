/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/02
 *
 * Source : https://leetcode-cn.com/problems/longest-valid-parentheses/
 * Problem:	Longest Valid Parentheses
 *
 */
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
 public:
   int longestValidParentheses(string s) {
     vector<int> dp(s.size(), 0);
     int m = 0;
     // 以')'结尾的位置是有效的，只更新这些位置的长度
     for (int i = 1; i < s.size(); ++i) {
       if (s[i] == ')') {
         if (s[i - 1] == '(') {
           // ...()
           dp[i] = (i - 2 >= 0 ? dp[i - 2] + 2 : 2);
         } else if (s[i - 1] == ')') {
           if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
             // ...((...))
             dp[i] = dp[i - 1] + 2;
             if (i - dp[i - 1] - 2 >= 0) {
               dp[i] += dp[i - dp[i - 1] - 2];
             }
           }
         }
         m = std::max(m, dp[i]);
       }
     }
     return m;
   }
};
