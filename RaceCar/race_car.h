/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/24
 *
 * Source : https://leetcode-cn.com/problems/race-car/
 * Problem: Race Car
 *
 */
#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;

class Solution {
 public:
   Solution() {
     memset(dp, 0, sizeof(int) * 10001);
   }

   int racecar(int target) {
     if (dp[target] > 0) {
       return dp[target];
     }
     int s = floor(log2(target)) + 1;
     if (target == (1 << s) - 1) {
       // target正好是2^s - 1, 向前走s次完成
       dp[target] = s;
     } else {
       // 向前走s次，向后走完成
       dp[target] = s + 1 + racecar((1 << s) - 1 - target);
       // 向前走s - 1次，向后走j（0 <= j < s - 1）次，然后向前走完成
       // s - 1种走法，取最小值
       for (int j = 0; j < s - 1; ++j) {
         dp[target] = std::min(dp[target], s + j + 1 + racecar(target - (1 << (s - 1)) + (1 << j)));
       }
     }
     return dp[target];
   }

 private:
   // 1 <= target <= 10000
   int dp[10001];
};
