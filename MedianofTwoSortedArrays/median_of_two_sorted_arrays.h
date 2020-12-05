/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2020/12/05
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem:	Median of Two Sorted Arrays
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     if (nums1.size() > nums2.size()) {
       return findMedianSortedArrays(nums2, nums1);
     }

     int m = nums1.size();
     int n = nums2.size();
     int left = 0;
     int right = m;
     int median1 = 0;
     int median2 = 0;
     while (left <= right) {
       int i = (left + right) / 2;
       int pre_i = (i == 0) ? INT_MIN : nums1[i - 1];
       int elem_i = (i == m) ? INT_MAX : nums1[i];
       int j = (m + n + 1) / 2 - i;
       int pre_j = (j == 0) ? INT_MIN : nums2[j - 1];
       int elem_j = (j == n) ? INT_MAX : nums2[j];
       if (pre_i <= elem_j) {
         left = i + 1;
         median1 = std::max(pre_i, pre_j);
         median2 = std::min(elem_i, elem_j);
       } else {
         right = i - 1;
       }
     }

     return ((m + n) % 2 == 0) ? (median1 + median2) / 2.0 : median1;
   }
};
