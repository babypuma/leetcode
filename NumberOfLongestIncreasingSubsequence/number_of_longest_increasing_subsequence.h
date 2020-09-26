/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/26
 *
 * Source : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * Problem:	Number of Longest Increasing Subsequence
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
 public:
   int findNumberOfLIS(vector<int>& nums) {
     vector<int> dp(nums.size(), 1);
     vector<int> count(nums.size(), 1);
     for (size_t i = 1; i < dp.size(); ++i) {
       for (size_t j = 0; j < i; ++j) {
         if (nums[j] < nums[i]) {
           if (dp[i] < dp[j] + 1) {
             dp[i] = dp[j] + 1;
             count[i] = count[j];
           } else if (dp[i] == dp[j] + 1) {
             count[i] += count[j];
           }
         }
       }
     }

     int max = 0;
     int num = 0;
     for (size_t i = 0; i < dp.size(); ++i) {
       if (max < dp[i]) {
         max = dp[i];
         num = count[i];
       } else if (max == dp[i]) {
         num += count[i];
       }
     }
     return num;
   }
};
