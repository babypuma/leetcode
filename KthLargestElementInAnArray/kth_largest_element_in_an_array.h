/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/02
 *
 * Source : https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * Problem: Kth Largest Element in an Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int findKthLargest(vector<int>& nums, int k) {
     int left = 0;
     int right = nums.size() - 1;
     int n = partition(nums, left, right);
     k = nums.size() - k;
     while (n != k) {
       if (n > k) {
         right = n - 1;
       } else {
         left = n + 1;
       }
       n = partition(nums, left, right);
     }
     return nums[k];
   }

 private:
   int partition(vector<int>& nums, int left, int right) {
     if (left == right) {
       return left;
     }

     int v = right;
     int i = left - 1;
     int j = right;
     for (;;) {
       while (nums[++i] < nums[v]) {
       }
       while (nums[v] < nums[--j]) {
         if (j == left) {
           break;
         }
       }
       if (i >= j) {
         break;
       }
       std::swap(nums[i], nums[j]);
     }
     std::swap(nums[i], nums[v]);
     return i;
   }
};
