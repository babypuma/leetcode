/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 * Update : 2020/12/08
 *
 * Source : https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * Problem:	Search in Rotated Sorted Array 
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int search(vector<int>& nums, int target) {
     return binarySearch(nums, 0, nums.size() - 1, target);
   }

 private:
   int binarySearch(const vector<int>& nums, int left, int right, int target) {
     if (left <= right) {
       int mid = (left + right) / 2;
       if (target == nums[mid]) {
         return mid;
       }

       if (nums[left] < nums[right]) {
         if (target > nums[mid]) {
           return binarySearch(nums, mid + 1, right, target);
         } else {
           return binarySearch(nums, left, mid - 1, target);
         }
       }

       // nums[left] > nums[right]
       if (nums[left] < nums[mid]) {
         if (target >= nums[left] && target < nums[mid]) {
           return binarySearch(nums, left, mid - 1, target);
         } else {
           return binarySearch(nums, mid + 1, right, target);
         }
       } else if (nums[left] > nums[mid]) {
         if (target > nums[mid] && target <= nums[right]) {
           return binarySearch(nums, mid + 1, right, target);
         } else {
           return binarySearch(nums, left, mid - 1, target);
         }
       }

       // nums[left] == nums[mid]
       return binarySearch(nums, mid + 1, right, target);
     }
     return -1;
   }
};
