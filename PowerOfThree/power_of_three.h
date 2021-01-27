/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/27
 *
 * Source : https://leetcode-cn.com/problems/power-of-three/
 * Problem: Power of Three
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   bool isPowerOfThree(int n) {
     if (n <= 0) {
       return false;
     }
     while (n % 3 == 0) {
       n /= 3;
     }
     return n == 1;
   }
};
