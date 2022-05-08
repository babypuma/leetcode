/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/08
 *
 * Source : https://leetcode-cn.com/contest/weekly-contest-292/problems/largest-3-same-digit-number-in-string/
 * Problem: Largest 3-Same-Digit Number in String
 *
 */
#include <string>
using std::string;

class Solution {
 public:
   string largestGoodInteger(string num) {
     size_t sz = num.size();
     string largest;
     size_t i = 0;
     while (i + 3 <= sz) {
       if (num[i] != num[i + 1]) {
         ++i;
         continue;
       }
       if (num[i + 1] == num[i + 2]) {
         if (largest < num.substr(i, 3)) {
           largest = num.substr(i, 3);
         }
         i = i + 3;
       } else {
         i = i + 2;
       }
     }

     return largest;
   }
};
