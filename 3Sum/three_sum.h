/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2020/11/16
 *
 * Source : https://leetcode-cn.com/problems/minimum-window-substring/
 * Problem:	Minimum Window Substring
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<vector<int> > threeSum(vector<int>& nums) {
     vector<vector<int> > vec2;
     if (nums.empty()) {
       return vec2;
     }

     std::sort(nums.begin(), nums.end());
     int sz = nums.size();
     for (int i = 0; i < sz - 2; ++i) {
       if (i > 0 && nums[i] == nums[i - 1]) {
         continue;
       }
       int left = i + 1;
       int right = sz - 1;
       while (left < right) {
         if (nums[i] + nums[left] + nums[right] > 0) {
           --right;
         } else if (nums[i] + nums[left] + nums[right] < 0) {
           ++left;
         } else {
           if (vec2.empty() || vec2.back().at(0) != nums[i] || vec2.back().at(1) != nums[left]) {
             vec2.push_back(vector<int>());
             vec2.back().push_back(nums[i]);
             vec2.back().push_back(nums[left]);
             vec2.back().push_back(nums[right]);
           }
           ++left;
           --right;
         }
       }
     }
     return vec2;
   }
};
