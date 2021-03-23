/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/23
 *
 * Source : https://leetcode-cn.com/problems/maximum-ascending-subarray-sum/
 * Problem: Maximum Ascending Subarray Sum
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxAscendingSum(vector<int>& nums) {
     int ans = 0;
     int sum = nums[0];
     for (int i = 1; i < nums.size(); ++i) {
       if (nums[i] > nums[i - 1]) {
         sum += nums[i];
       } else {
         ans = std::max(ans, sum);
         sum = nums[i];
       }
     }
     return ans > sum ? ans : sum;
   }
};
