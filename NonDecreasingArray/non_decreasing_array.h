/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/12
 *
 * Source : https://leetcode-cn.com/problems/non-decreasing-array/
 * Problem: Non-decreasing Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool checkPossibility(vector<int>& nums) {
     int count = 0;
     for (size_t i = 0; i < nums.size() - 1; ++i) {
       if (nums[i] > nums[i + 1]) {
         return get(nums, i - 1) <= get(nums, i + 1) && check(nums, i + 1) || 
           get(nums, i) <= get(nums, i + 2) && check(nums, i + 2);
       }
     }
     return true;
   }

 private:
   int get(vector<int>& nums, int i) {
     if (i < 0) {
       return INT32_MIN;
     } else if (i > nums.size() - 1) {
       return INT32_MAX;
     }
     return nums[i];
   }

   bool check(vector<int>& nums, size_t start) {
     for (size_t i = start; i < nums.size() - 1; ++i) {
       if (nums[i] > nums[i + 1]) {
         return false;
       }
     }
     return true;
   }
};
