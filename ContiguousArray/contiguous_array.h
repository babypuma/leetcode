/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/04
 *
 * Source : https://leetcode-cn.com/problems/contiguous-array/
 * Problem:	Contiguous Array
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int findMaxLength(vector<int>& nums) {
     int sum = 0;
     int ans = 0;
     unordered_map<int, int> prefix_sum;
     for (int i = 0; i < nums.size(); ++i) {
       sum += (nums[i] == 0) ? -1 : 1;
       if (sum == 0) {
         ans = std::max(ans, i + 1);
       }
       if (prefix_sum.count(sum) > 0) {
         ans = std::max(ans, i - prefix_sum[sum]);
       } else {
         prefix_sum[sum] = i;
       }
     }

     return ans;
   }
};
