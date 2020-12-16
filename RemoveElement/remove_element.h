/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/remove-element/
 * Problem:	Remove Element
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int removeElement(vector<int>& nums, int val) {
     size_t back = 0;
     size_t front = 0;
     while (front < nums.size()) {
       if (nums[front] == val) {
         ++front;
         continue;
       }

       if (back != front) {
         nums[back] = nums[front];
       }
       ++front;
       ++back;
     }

     return back;
   }
};
