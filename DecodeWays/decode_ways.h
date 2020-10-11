/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/11
 *
 * Source : https://leetcode-cn.com/problems/decode-ways/
 * Problem:	Decode Ways
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   int numDecodings(string s) {
     vector<int> dp(s.size() + 1, 0);
     dp[0] = 1;
     dp[1] = (s[0] == '0' ? 0 : 1);
     for (size_t i = 2; i < dp.size(); ++i) {
       int c1 = (s[i - 1] != '0' ? 1 : 0);
       int d2 = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
       int c2 = (d2 >= 10 && d2 <= 26 ? 1 : 0);
       dp[i] = c1 * dp[i - 1] + c2 * dp[i - 2];
     }
     return dp.back();
   }
};
