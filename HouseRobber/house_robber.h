/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2020/09/27
 *
 * Source : https://leetcode-cn.com/problems/house-robber/
 * Problem:	House Robber
 *
 */
#include <vector>
using std::vector;
using std::max;

class Solution {
 public: 
   int rob(vector<int>& nums) {
     if (nums.empty()) {
       return 0;
     }
     if (nums.size() == 1) {
       return nums[0];
     }
     vector<int> dp(nums.size());
     dp[0] = nums[0];
     dp[1] = max(dp[0], nums[1]);
     for (size_t i = 2; i < nums.size(); ++i) {
       dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
     }
     return dp.back();
   }
};
