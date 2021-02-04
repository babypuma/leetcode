/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/move-zeroes/
 * Problem: Move Zeroes
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   void moveZeroes(vector<int>& nums) {
     int sz = nums.size();
     int left = 0;
     int right = 0;
     while (right < sz) {
       if (nums[right] != 0) {
         std::swap(nums[left], nums[right]);
         ++left;
       }
       ++right;
     }
   }
};
