/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/12
 *
 * Source : https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * Problem: Single Element in a Sorted Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int singleNonDuplicate(vector<int>& nums) {
     return binarySearch(nums, 0, nums.size() - 1);
   }

 private:
   int binarySearch(vector<int>& nums, int left, int right) {
     if (left == right) {
       return nums[left];
     }

     int mid = (left + right) / 2;
     if ((mid - left) % 2 == 0) {
       if (nums[mid] == nums[mid - 1]) {
         return binarySearch(nums, left, mid - 2);
       } else if (nums[mid] == nums[mid + 1]) {
         return binarySearch(nums, mid + 2, right);
       } else {
         return nums[mid];
       }
     } else {
       if (nums[mid] == nums[mid - 1]) {
         return binarySearch(nums, mid + 1, right);
       } else if (nums[mid] == nums[mid + 1]) {
         return binarySearch(nums, left, mid - 1);
       } else {
         return nums[mid];
       }
     }
   }
};
