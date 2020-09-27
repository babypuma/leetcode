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
     vector<int> inc(nums.begin(), nums.end());
     vector<int> exc(nums.size(), 0);
     exc[1] = nums[0];
     for (size_t i = 2; i < nums.size(); ++i) {
       inc[i] = max(exc[i - 1] + nums[i], inc[i - 2] + nums[i]);
       exc[i] = max(max(inc[i - 1], inc[i - 2]), max(exc[i - 1], exc[i - 2]));
     }
     return max(inc.back(), exc.back());
   }
};
