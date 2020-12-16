/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/reverse-integer/
 * Problem: Reverse Integer
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int reverse(int x) {
     if (x == 0 || x == INT32_MIN) {
       return 0;
     }

     int sign = x > 0 ? 1 : -1;
     if (x < 0) {
       x = -x;
     }

     vector<int> bits;
     while (x > 0) {
       bits.push_back(x % 10);
       x /= 10;
     }

     int64_t y = 0;
     for (auto& i : bits) {
       y *= 10;
       y += i;
     }

     return y > INT32_MAX ? 0 : y * sign;
   }
};
