/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/29
 *
 * Source : https://leetcode-cn.com/problems/remove-duplicate-letters/
 * Problem: Remove Duplicate Letters
 *               
 */
#include <string>
#include <vector>
#include <bitset>
using std::string;
using std::vector;
using std::bitset;

class Solution {
 public:
   string removeDuplicateLetters(string s) {
     vector<int> ch_count(CHAR_NUM);
     for (auto& ch : s) {
       ++ch_count[ch - 'a'];
     }

     string str;
     bitset<CHAR_NUM> used;
     for (auto& ch : s) {
       if (used.test(ch - 'a')) {
         --ch_count[ch - 'a'];
         continue;
       }
       while (!str.empty() && str.back() >= ch && ch_count[str.back() - 'a'] > 1) {
         --ch_count[str.back() - 'a'];
         used.reset(str.back() - 'a');
         str.pop_back();
       }
       str.push_back(ch);
       used.set(ch - 'a');
     }

     return str;
   }

 private:
   static const int CHAR_NUM = 26;
};
