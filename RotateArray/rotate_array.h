/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2021/01/08
 *
 * Source : https://leetcode-cn.com/problems/rotate-array/
 * Problem:	Rotate Array
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   void rotate(vector<int>& nums, int k) {
     size_t size = nums.size();
     if ((k %= size) == 0) {
       return;
     }
     reverse(nums, 0, size);
     reverse(nums, 0, k);
     reverse(nums, k, size - k);
   }

   void reverse(vector<int>& vec, size_t pos, size_t len) {
     if (pos < 0 || pos >= vec.size() || len < 0) {
       return;
     }
     int left = pos;
     int right = pos + len - 1;
     while (left < right) {
       std::swap(vec[left], vec[right]);
       ++left;
       --right;
     }
   }
};
