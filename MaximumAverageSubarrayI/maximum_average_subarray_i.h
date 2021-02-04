/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/maximum-average-subarray-i/
 * Problem: Maximum Average Subarray I
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   double findMaxAverage(vector<int>& nums, int k) {
     int64_t sum = 0;
     for (int i = 0; i < k; ++i) {
       sum += nums[i];
     }
     int64_t ans = sum;
     for (int i = k; i < nums.size(); ++i) {
       sum -= nums[i - k]; 
       sum += nums[i];
       ans = std::max(ans, sum);
     }
     return static_cast<double>(ans) / k;
   }
};
