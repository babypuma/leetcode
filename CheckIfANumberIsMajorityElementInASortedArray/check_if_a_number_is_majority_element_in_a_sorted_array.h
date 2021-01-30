/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/30
 *
 * Source : https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/
 * Problem: Check If a Number Is Majority Element in a Sorted Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool isMajorityElement(vector<int>& nums, int target) {
     int sz = nums.size();
     int low = binarySearchLow(nums, 0, sz - 1, target);
     if (low == -1) {
       return false;
     }
     int high = binarySearchHigh(nums, 0, sz - 1, target);
     return high - low + 1 > sz / 2;
   }

 private:
   int binarySearchLow(vector<int>& nums, int left, int right, int val) {
     if (left > right) {
       return -1;
     }
     int mid = left + (right - left) / 2;
     if (nums[mid] == val) {
       int idx = binarySearchLow(nums, left, mid - 1, val);
       return idx == -1 ? mid : idx;
     }
     if (nums[mid] < val) {
       return binarySearchLow(nums, mid + 1, right, val);
     }
     return binarySearchLow(nums, left, mid - 1, val);
   }

   int binarySearchHigh(vector<int>& nums, int left, int right, int val) {
     if (left > right) {
       return -1;
     }
     int mid = left + (right - left) / 2;
     if (nums[mid] == val) {
       int idx = binarySearchHigh(nums, mid + 1, right, val);
       return idx == -1 ? mid : idx;
     }
     if (nums[mid] < val) {
       return binarySearchHigh(nums, mid + 1, right, val);
     }
     return binarySearchHigh(nums, left, mid - 1, val);
   }
};
