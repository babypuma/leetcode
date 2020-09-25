/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/10
 * Update : 2020/09/25
 *
 * Source : https://leetcode.com/problems/longest-increasing-subsequence/
 * Problem:	Longest Increasing Subsequence
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
 public:
   int lengthOfLIS(vector<int>& nums) {
     vector<int> dp(nums.size(), 1);
     for (size_t i = 1; i < nums.size(); ++i) {
       for (size_t j = 0; j < i; ++j) {
         if (nums[j] < nums[i]) {
           dp[i] = std::max(dp[i], dp[j] + 1);
         }
       }
     }
     int max = 0;
     for (size_t i = 0; i < dp.size(); ++i) {
       if (dp[i] > max) {
         max = dp[i];
       }
     }
     return max;
   }
};
