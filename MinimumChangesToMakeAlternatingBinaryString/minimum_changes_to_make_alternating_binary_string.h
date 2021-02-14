/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/14
 *
 * Source : https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string/
 * Problem: Minimum Changes To Make Alternating Binary String
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   int minOperations(string s) {
     int num1 = 0;
     int num2 = 0;
     char ch1 = '0';
     char ch2 = '1';
     for (size_t i = 0; i < s.size(); ++i) {
       if (s[i] != ch1) {
         ++num1;
       }
       if (s[i] != ch2) {
         ++num2;
       }
       std::swap(ch1, ch2);
     }

     return std::min(num1, num2);
   }
};
