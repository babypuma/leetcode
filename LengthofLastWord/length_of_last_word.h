/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 * Update : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/length-of-last-word/
 * Problem:	Length of Last Word
 *
 */
#include <string>
using std::string;

class Solution {
 public:
   int lengthOfLastWord(string s) {
     int j = s.size() - 1;
     while (j >= 0 && s[j] == ' ') {
       --j;
     }
     if (j < 0) {
       return 0;
     }

     int i = j;
     while (i >= 0 && s[i] != ' ') {
       --i;
     }
     return j - i;
   }
};
