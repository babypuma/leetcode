/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * Problem:	Remove Duplicates from Sorted Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int removeDuplicates(vector<int>& nums) {
     int start = 0;
     int i = 0;
     int sz = nums.size();
     while (i < sz) {
       int j = i + 1;
       while (j < sz && nums[j] == nums[j - 1]) {
         ++j;
       }
       if (i != start) {
         nums[start] = nums[i];
       }
       ++start;
       i = j;
     }

     return start;
   }
};
