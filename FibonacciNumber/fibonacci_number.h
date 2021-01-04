/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/04
 *
 * Source : https://leetcode-cn.com/problems/fibonacci-number/
 * Problem: Fibonacci Number
 *               
 */
class Solution {
 public:
   int fib(int n) {
     if (n < 2) {
       return n;
     }
     
     int f0 = 0;
     int f1 = 1;
     int fib = 0;
     n -= 2;
     while (n-- >= 0) {
       fib = f0 + f1;
       f0 = f1;
       f1 = fib;
     }
     return fib;
   }
};
