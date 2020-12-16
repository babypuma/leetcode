/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 * Update : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/add-binary/
 * Problem:	Add Binary
 *
 */
#include <string>
using std::string;

class Solution {
 public:
   string addBinary(string a, string b) {
     if (a.size() > b.size()) {
       return addBinary(b, a);
     }
     std::reverse(a.begin(), a.end());
     std::reverse(b.begin(), b.end());

     string sum;
     char carry = '0';
     size_t i = 0;
     while (i < a.size()) {
       sum += internalAdd(a[i], b[i], carry);
       ++i;
     }
     while (i < b.size()) {
       sum += internalAdd('0', b[i], carry);
       ++i;
     }
     if (carry == '1') {
       sum += '1';
     }
     std::reverse(sum.begin(), sum.end());

     return sum;
   }

 private:
   char internalAdd(char ch1, char ch2, char& carry) {
     int n1 = ch1 - '0';
     int n2 = ch2 - '0';
     int c = carry - '0';
     int sum = n1 + n2 + c;

     carry = (sum >= 2) ? '1' : '0';
     return (sum % 2) + '0';
   }
};
