/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/06
 * Update : 2020/12/07
 *
 * Source : https://leetcode-cn.com/problems/next-permutation/
 * Problem:	Next Permutation
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
 public:
   void nextPermutation(vector<int>& nums) {
     int sz = nums.size();
     int i = sz - 2;
     while (i >= 0 && nums[i] >= nums[i + 1]) {
       --i;
     }
     if (i >= 0) {
       int j = sz - 1;
       while (nums[i] >= nums[j]) {
         j--;
       }
       std::swap(nums[i], nums[j]);
     }
     std::reverse(nums.begin() + i + 1, nums.end());
   }
};
