/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/09
 *
 * Source : https://leetcode-cn.com/problems/minimum-elements-to-add-to-form-a-given-sum/
 * Problem: Minimum Elements to Add to Form a Given Sum
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int minElements(vector<int>& nums, int limit, int goal) {
     int64_t sum = 0;
     for (auto& n : nums) {
       sum += n;
     }
     int64_t gap = std::abs(goal - sum);
     return gap / limit + (gap % limit == 0 ? 0 : 1);
   }
};
