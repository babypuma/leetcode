/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/single-number-iii/
 * Problem:	Single Number III
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> singleNumber(vector<int>& nums) {
     int x = 0;
     for (auto& n : nums) {
       x ^= n;
     }

     // mask保留x最低位上的1,其他位置0
     int mask = (x == INT_MIN) ? x : x & (-x);
     int one = 0;
     for (auto& n : nums) {
       if (mask & n) {
         one ^= n;
       }
     }

     vector<int> vec;
     vec.push_back(one);
     vec.push_back(one ^ x);
     return vec;
   }
};
