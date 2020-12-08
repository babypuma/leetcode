/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/09
 *
 * Source : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Problem:	Find First and Last Position of Element in Sorted Array
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> searchRange(vector<int>& nums, int target) {
     vector<int> vec;
     vec.push_back(binarySearch(nums, target, true));
     vec.push_back(binarySearch(nums, target, false));
     return vec;
   }

 private:
   int binarySearch(const vector<int>& nums, int target, bool lower) {
     if (nums.empty()) {
       return -1;
     }
     int left = 0;
     int right = nums.size() - 1;
     int idx = -1;
     while (left <= right) {
       int mid = (left + right) / 2;
       if (target == nums[mid]) {
         idx = mid;
       }
       if (target < nums[mid]) {
         right = mid - 1;
       } else if (target > nums[mid]) {
         left = mid + 1;
       } else {
         // target == nums[mid]
         lower ? (right = mid - 1) : (left = mid + 1);
       }
     }
     return idx;
   }
};
