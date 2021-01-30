/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/30
 *
 * Source : https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 * Problem: Bitwise AND of Numbers Range
 *               
 */
class Solution {
 public:
   int rangeBitwiseAnd(int m, int n) {
     if (m <= 0 || n <= 0 || mostSignificantBit(m) != mostSignificantBit(n)) {
       return 0;
     }
     int sum = 0;
     int b = 1 << (mostSignificantBit(m) - 1);
     sum += b;
     sum += rangeBitwiseAnd(m - b, n - b);
     return sum;
   }

 private:
   int mostSignificantBit(int num) {
     int c = 0;
     while (num > 0) {
       num >>= 1;
       ++c;
     }
     return c;
   }
};
