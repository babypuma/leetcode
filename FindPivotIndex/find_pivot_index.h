/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/06
 *
 * Source : https://leetcode-cn.com/problems/find-pivot-index/
 * Problem:	Find Pivot Index
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int pivotIndex(vector<int>& nums) {
     int n = nums.size();
     vector<int> left_sum(n, 0);
     vector<int> right_sum(n, 0);
     for (int i = 1; i < n; ++i) {
       left_sum[i] = nums[i - 1] + left_sum[i - 1];
     }
     for (int i = n - 2; i >= 0; --i) {
       right_sum[i] = nums[i + 1] + right_sum[i + 1];
     }
     for (int i = 0; i < n; ++i) {
       if (left_sum[i] == right_sum[i]) {
         return i;
       }
     }

     return -1;
   }
};
