/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/one-edit-distance/
 * Problem: One Edit Diatance
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   bool isOneEditDistance(string s, string t) {
     int sz = std::min(s.size(), t.size());
     for (int i = 0; i < sz; ++i) {
       if (s[i] != t[i]) {
         return equal(s, i, t, i + 1) || equal(s, i + 1, t, i) || equal(s, i + 1, t, i + 1);
       }
     }
     return s.size() + 1 ==  t.size() || t.size() + 1 == s.size();
   }

 private:
   bool equal(string& s, int start1, string& t, int start2) {
     int sz1 = s.size();
     int sz2 = t.size();
     if (sz1 - start1 != sz2 - start2) {
       return false;
     }
     while (start1 < sz1 && start2 < sz2) {
       if (s[start1++] != t[start2++]) {
         return false;
       }
     }
     return true;
   }
};
