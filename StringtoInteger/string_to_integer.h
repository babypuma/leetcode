/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/string-to-integer-atoi/
 * Problem: String to Integer (atoi)
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int myAtoi(string s) {
     size_t i = 0;
     for (; i < s.size() && s[i] == ' '; ++i) {
     }

     int sign = 1;
     if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
       if (s[i] == '-') {
         sign = -1;
       }
       ++i;
     }

     if (i < s.size() && !isdigit(s[i])) {
       return 0;
     }

     int num = 0;
     for (; i < s.size() && isdigit(s[i]); ++i) {
       if (num > 0 && sign < 0) {
         num *= sign;
       }
       if (sign > 0 && num > (INT32_MAX - (s[i] - '0')) / 10) {
         num = INT32_MAX;
         break;
       }
       if (sign < 0 && num < (INT32_MIN + (s[i] - '0')) / 10) {
         num = INT32_MIN;
         break;
       }
       num *= 10;
       int incr = s[i] - '0';
       num = (sign > 0) ? num + incr : num - incr;
     }

     return num;
   }
};
