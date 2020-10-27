/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/27
 *
 * Source : https://leetcode-cn.com/problems/2-keys-keyboard/
 * Problem:	2 Keys Keyboard
 *
 */
class Solution {
 public:
   int minSteps(int n) {
     int m = 2;
     int ans = 0;
     while (n > 1) {
       while (n % m == 0) {
         ans += m;
         n /= m;
       }
       m++;
     }
     return ans;
   }
};
