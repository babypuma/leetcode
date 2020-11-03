/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/03
 *
 * Source : https://leetcode-cn.com/problems/maximum-size-subarray-sum-equals-k/
 * Problem:	Maximum Size Subarray Sum Equals K
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int maxSubArrayLen(vector<int>& nums, int k) {
     unordered_map<int, int> prefix_sum;
     int sum = 0;
     int ans = 0;
     for (int i = 0; i < nums.size(); ++i) {
       sum += nums[i];
       if (sum == k) {
         ans = std::max(ans, i + 1);
       }
       if (prefix_sum.count(sum - k) > 0) {
         ans = std::max(ans, i - prefix_sum[sum - k]);
       }
       if (prefix_sum.count(sum) == 0) {
         prefix_sum[sum] = i;
       }
     }

     return ans;
   }
};
