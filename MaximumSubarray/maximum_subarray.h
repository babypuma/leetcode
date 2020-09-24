/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/17
 * Update : 2020/09/25
 *
 * Source : https://leetcode.com/problems/maximum-subarray/
 * Problem:	Maximum Subarray
 *
 */
#include <vector>
using std::vector;

class Solution {
 public: 
   int maxSubArray(vector<int>& nums) {
     int dp[nums.size()];
     dp[0] = nums[0];
     int max = dp[0];
     for (size_t i = 1; i < nums.size(); ++i) {
       dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
       if (max < dp[i]) {
         max = dp[i];
       }
     }
     return max;
   }
};
