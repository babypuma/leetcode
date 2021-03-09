/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/09
 *
 * Source : https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 * Problem: Check if Binary String Has at Most One Segment of Ones
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   bool checkOnesSegment(string s) {
     int sz = s.size();
     for (int i = 0; i < sz - 1; ++i) {
       if (s[i] == '0' && s[i + 1] == '1') {
         return false;
       }
     }
     return true;
   }
};
