/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/07
 *
 * Source : https://leetcode-cn.com/problems/maximum-score-from-removing-stones/
 * Problem: Maximum Score From Removing Stones
 *               
 */
class Solution {
 public:
   int maximumScore(int a, int b, int c) {
     if (a > b) {
       std::swap(a, b);
     }
     if (a > c) {
       std::swap(a, c);
     }
     if (b > c) {
       std::swap(b, c);
     }
     if (a + b <= c) {
       return a + b;
     }
     return c + (a + b - c)/2;
   }
};
