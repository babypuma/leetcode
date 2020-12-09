/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/10
 *
 * Source : https://leetcode-cn.com/problems/last-stone-weight-ii/
 * Problem:	Last Stone Weight II
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int lastStoneWeightII(vector<int>& stones) {
     int sum = 0;
     for (auto& val: stones) {
       sum += val;
     }

     int target = sum / 2;
     vector<int> dp(target + 1, 0);
     int sz = stones.size();
     for (int i = 0; i < sz; ++i) {
       int weight = stones[i];
       for (int j = target; j >= weight; --j) {
         dp[j] = std::max(dp[j], dp[j - weight] + weight);
       }
     }

     return sum - 2 * dp[target];
   }
};
