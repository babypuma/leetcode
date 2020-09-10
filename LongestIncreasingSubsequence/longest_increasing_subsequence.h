/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/10
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
     int sz = nums.size();
     vector<int32_t> piles(sz + 1, INT32_MAX);
     for (size_t i = 0; i < sz; ++i) {
       size_t j = std::lower_bound(piles.begin(), piles.end(), nums[i]) - piles.begin();
       piles[j] = nums[i];
     }
     for (size_t i = 0; i < sz + 1; ++i) {
       if (piles[i] == INT32_MAX) {
         return i;
       }
     }
     return 0;
   }
};
