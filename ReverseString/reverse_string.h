/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/reverse-string/
 * Problem: Reverse String
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   void reverseString(vector<char>& s) {
     int i = 0;
     int j = s.size() - 1;
     while (i < j) {
       char ch = s[i];
       s[i] = s[j];
       s[j] = ch;
       ++i;
       --j;
     }
   }
};
