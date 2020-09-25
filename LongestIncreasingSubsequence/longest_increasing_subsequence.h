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
     return greedy(nums);
   }

 private:
   // DP算法，dp[i]表示以num[i]为结尾的最长LIS，时间复杂度O(n^2)
   int dp(vector<int>& nums) {
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

   // Greedy算法，时间复杂度为O(nlogn)
   int greedy(vector<int>& nums) {
     vector<int> piles(nums.size(), INT_MAX);
     for (size_t i = 0; i < nums.size(); ++i) {
       vector<int>::iterator it = lower_bound(piles.begin(), piles.end(), nums[i]);
       int j = it - piles.begin();
       piles[j] = nums[i];
     }
     return lower_bound(piles.begin(), piles.end(), INT_MAX) - piles.begin();
   }
};
