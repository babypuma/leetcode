/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/21
 *
 * Source : https://leetcode-cn.com/problems/merge-strings-alternately/
 * Problem: Merge Strings Alternately
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   string mergeAlternately(string word1, string word2) {
     int sz1 = word1.size();
     int sz2 = word2.size();
     int sz = std::min(sz1, sz2);
     string m;
     for (int i = 0; i < sz; ++i) {
       m += word1[i];
       m += word2[i];
     }
     if (sz1 < sz2) {
       m += word2.substr(sz);
     } else if (sz2 < sz1) {
       m += word1.substr(sz);
     }
     return m;
   }
};
