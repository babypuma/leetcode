/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/04
 *
 * Source : https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 * Problem:	Count Number of Nice Subarrays
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int numberOfSubarrays(vector<int>& nums, int k) {
     int sum = 0;
     int count = 0;
     unordered_map<int, int> prefix_sum;
     for (int i = 0; i < nums.size(); ++i) {
       if (nums[i] & 0x1 == 1) {
         ++sum;
       }
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
