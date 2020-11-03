/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/02
 *
 * Source : https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * Problem:	Subarray Sum Equals K
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int subarraySum(vector<int>& nums, int k) {
     unordered_map<int, int> prefix_sum;
     int sum = 0;
     int count = 0;
     for (int i = 0; i < nums.size(); ++i) {
       sum += nums[i];
       if (sum == k) {
         ++count;
       }
       if (prefix_sum.count(sum - k) > 0) {
         count += prefix_sum[sum - k];
       }
       ++prefix_sum[sum];
     }
     return count;
   }
};
