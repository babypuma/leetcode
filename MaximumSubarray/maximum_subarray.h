/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/17
 * Update : 2020/09/25,2020/11/09
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
     int pre = 0;
     int ans = nums[0];
     for (int i = 0; i < nums.size(); ++i) {
       pre = std::max(pre + nums[i], nums[i]);
       ans = std::max(ans, pre);
     }
     return ans;
   }
};
