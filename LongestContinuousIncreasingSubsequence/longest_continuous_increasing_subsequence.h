/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
 * Problem: Longest Continuous Increasing Subsequence
 *
 */
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
 public:
   int findLengthOfLCIS(vector<int>& nums) {
     if (nums.empty()) {
       return 0;
     }

     int sz = nums.size();
     int ans = 0;
     int start = 0;
     for (int i = 1; i < sz; ++i) {
       if (nums[i] > nums[i - 1]) {
         continue;
       }
       ans = std::max(ans, i - start);
       start = i;
     }
     ans = std::max(ans, sz - start);

     return ans;
   }
};
