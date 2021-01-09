/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/09
 *
 * Source : https://leetcode-cn.com/problems/count-and-say/
 * Problem: Count and Say
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   string countAndSay(int n) {
     string str("1");
     while (--n > 0) {
       string next;
       char prev = str[0];
       int count = 1;
       for (size_t i = 1; i < str.size(); ++i) {
         if (str[i] == str[i - 1]) {
           ++count;
         } else {
           next += static_cast<char>('0' + count);
           next += prev;
           prev = str[i];
           count = 1;
         }
       }
       next += static_cast<char>('0' + count);
       next += prev;
       str.swap(next);
     }

     return str;
   }
};
