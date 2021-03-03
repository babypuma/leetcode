/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/12
 * Update : 2021/03/03
 *
 * Source : https://leetcode-cn.com/problems/counting-bits/
 * Problem:	Counting Bits
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> countBits(int num) {
     vector<int> dp(num + 1, 0);
     int high_bit = 0;
     for (int i = 1; i <= num; ++i) {
       if ((i & (i - 1)) == 0) {
         high_bit = i;
       }
       dp[i] = dp[i - high_bit] + 1;
     }
     return dp;
   }
};
