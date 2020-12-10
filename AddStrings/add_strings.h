/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/11
 *
 * Source : https://leetcode-cn.com/problems/add-strings/
 * Problem:	Add Strings
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   string addStrings(string num1, string num2) {
     if (num1.size() > num2.size()) {
       return addStrings(num2, num1);
     }

     std::reverse(num1.begin(), num1.end());
     std::reverse(num2.begin(), num2.end());
     int m = num1.size();
     int n = num2.size();
     char carry = '0';
     string sum;
     for (int i = 0; i < m; ++i) {
       sum += add(num1[i], num2[i], carry);
     }
     for (int i = m; i < n; ++i) {
       sum += add('0', num2[i], carry);
     }
     if (carry != '0') {
       sum += carry;
     }
     std::reverse(sum.begin(), sum.end());
     return sum;
   }

 private:
   char add(char ch1, char ch2, char& carry) {
     int n1 = ch1 - '0';
     int n2 = ch2 - '0';
     int c = carry - '0';
     int n = n1 + n2 + c;
     if (n >= 10) {
       n -= 10;
       carry = '1';
     } else {
       carry = '0';
     }
     return n + '0';
   }
};
