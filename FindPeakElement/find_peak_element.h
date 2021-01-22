/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/15
 * Update : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/find-peak-element/
 * Problem: Find Peak Element
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int findPeakElement(vector<int>& nums) {
     return find(nums, 0, nums.size() - 1);
   }

 private:
   int find(vector<int>& nums, int left, int right) {
     if (left == right) {
       return left;
     }
     int mid = (left + right) / 2;
     if (nums[mid] > nums[mid + 1]) {
       return find(nums, left, mid);
     } else {
       return find(nums, mid + 1, right);
     }
   }
};
