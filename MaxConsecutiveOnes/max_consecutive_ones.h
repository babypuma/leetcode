/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/15
 *
 * Source : https://leetcode-cn.com/problems/max-consecutive-ones/
 * Problem: Max Consecutive Ones
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int findMaxConsecutiveOnes(vector<int>& nums) {
     int ans = 0;
     int left = 0;
     int right = 0;
     int sz = nums.size();
     while (right < sz) {
       if (nums[right] == 0) {
         ans = std::max(ans, right - left);
         left = right;
       }
       ++right;

       if (nums[left] == 0) {
         ++left;
       }
     }
     ans = std::max(ans, right - left);

     return ans;
   }
};
