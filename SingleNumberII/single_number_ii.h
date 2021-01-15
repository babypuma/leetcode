/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/single-number-ii/
 * Problem:	Single Number II
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int singleNumber(vector<int>& nums) {
     int seen_once = 0;
     int seen_twice = 0;
     for (auto& n : nums) {
       seen_once = ~seen_twice & (seen_once ^ n);
       seen_twice = ~seen_once & (seen_twice ^ n);
     }
     return seen_once;
   }
};
