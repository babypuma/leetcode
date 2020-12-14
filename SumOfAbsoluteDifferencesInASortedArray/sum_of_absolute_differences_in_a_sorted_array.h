/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 * Problem:	Sum of Absolute Differences in a Sorted Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
     size_t sz = nums.size();
     vector<int> prefix_sum(sz, 0);
     vector<int> suffix_sum(sz, 0);
     for (int i = 1; i < sz; ++i) {
       prefix_sum[i] = nums[i - 1] + prefix_sum[i - 1];
     }
     for (int i = sz - 2; i >= 0; --i) {
       suffix_sum[i] = nums[i + 1] + suffix_sum[i + 1];
     }
     vector<int> sum(sz, 0);
     for (int i = 0; i < sz; ++i) {
       sum[i] = i * nums[i] - prefix_sum[i] + suffix_sum[i] - (sz - i - 1) * nums[i];
     }
     return sum;
   }
};
