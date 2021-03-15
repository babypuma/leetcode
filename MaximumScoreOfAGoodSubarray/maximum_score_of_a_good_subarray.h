/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/15
 *
 * Source : https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/
 * Problem: Maximum Score of a Good Subarray
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maximumScore(vector<int>& nums, int k) {
     int minimum = nums[k];
     int ans = minimum;
     int left = k;
     int right = k;
     int sz = nums.size();
     while (left >= 0 || right < sz) {
       while (left > 0 && nums[left - 1] >= minimum) {
         --left;
       }
       while (right < sz - 1 && nums[right + 1] >= minimum) {
         ++right;
       }
       ans = std::max(ans, (right - left + 1) * minimum);
       if (right - left + 1 == sz) {
         break;
       }
       if (left == 0) {
         minimum = nums[++right];
       } else if (right == sz - 1) {
         minimum = nums[--left];
       } else if (nums[left - 1] > nums[right + 1]) {
         minimum = nums[--left];
       } else {
         minimum = nums[++right];
       }
     }
     return ans;
   }
};
