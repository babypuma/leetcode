/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/07
 *
 * Source : https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated/
 * Problem: Check if Array Is Sorted and Rotated
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool check(vector<int>& nums) {
     int sz = nums.size();
     int start = 0;
     for (int i = 1; i < sz; ++i) {
       if (nums[i] < nums[i - 1]) {
         start = i;
         break;
       }
     }
     if (start == 0) {
       return true;
     }

     for (int i = start + 1; i < sz; ++i) {
       if (nums[i] < nums[i - 1]) {
         return false;
       }
     }
     return nums[sz - 1] <= nums[0];
   }
};
