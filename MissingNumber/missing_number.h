/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/05/20
 * Update : 2021/01/13
 *
 * Source : https://leetcode-cn.com/problems/missing-number/
 * Problem: Missing Number
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int missingNumber(vector<int>& nums) {
     int sum = nums.size() * (1 + nums.size()) / 2;
     for (auto& n : nums) {
       sum -= n;
     }
     return sum;
   }
};
