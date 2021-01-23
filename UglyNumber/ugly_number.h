/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/ugly-number/
 * Problem: Ugly Number
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool isUgly(int num) {
     if (num <= 0) {
       return false;
     }
     if (num == 1) {
       return true;
     }
     if (num % 5 == 0) {
       return isUgly(num / 5);
     } else if (num % 3 == 0) {
       return isUgly(num / 3);
     } else if (num % 2 == 0) {
       return isUgly(num / 2);
     }
     return false;
   }
};
