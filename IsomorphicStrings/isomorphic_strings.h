/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2021/01/20
 *
 * Source : https://leetcode-cn.com/problems/isomorphic-strings/
 * Problem:	Isomorphic Strings
 *
 */
#include <unordered_map>
#include <string>
#include <bitset>

using std::unordered_map;
using std::string;
using std::bitset;

class Solution {
 public: 
   bool isIsomorphic(string s, string t) {
     size_t sz = s.size();
     if (sz != t.size()) {
       return false;
     }

     bitset<CHAR_NUM> used_char;
     unordered_map<char, char> char_map;
     for (size_t i = 0; i < sz; ++i) {
       if (char_map.count(s[i])) {
         if (char_map[s[i]] != t[i]) {
           return false;
         }
       } else {
         if (used_char.test(t[i])) {
           return false;
         }
         used_char.set(t[i]);
         char_map[s[i]] = t[i];
       }
     }

     return true;
   }

 private:
   static const int CHAR_NUM = 256;
};
