/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/12
 *
 * Source : https://leetcode-cn.com/problems/counting-bits/
 * Problem:	Counting Bits
 *
 */
#include <vector>
#include <cmath>
using std::vector;

class Solution {
 public:
   vector<int> countBits(int num) {
     vector<int> dp(num + 1, 0);
     size_t i = 1;
     // num为2的整数次幂时，比特位计数为1
     while (i < dp.size()) {
       dp[i] = 1;
       i <<= 1;
     }
     // num为非2的整数次幂时，n比特位计数为num - 2^(floor(lg(num)))
     for (i = 2; i < dp.size(); ++i) {
       if (dp[i] == 1) {
         continue;
       }
       int prev = i - (1 << static_cast<int>(std::log2(i)));
       dp[i] = dp[prev] + 1;
     }
     return dp;
   }
};
