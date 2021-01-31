/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/31
 *
 * Source : https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/
 * Problem: Maximum Number of Balls in a Box
 *               
 */
#include <unordered_map>
using std::unordered_map;

class Solution {
 public:
   int countBalls(int lowLimit, int highLimit) {
     unordered_map<int, int> count;
     int ans = 0;
     for (int i = lowLimit; i <= highLimit; ++i) {
      ans = std::max(ans, ++count[convert(i)]);
     }
     return ans;
   }

 private:
   int convert(int num) {
     int c = 0;
     while (num > 0) {
       c += num % 10;
       num /= 10;
     }
     return c;
   }
};
