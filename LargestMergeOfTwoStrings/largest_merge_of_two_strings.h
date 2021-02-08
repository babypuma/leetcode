/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/07
 *
 * Source : https://leetcode-cn.com/problems/largest-merge-of-two-strings/
 * Problem: Largest Merge Of Two Strings
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   string largestMerge(string word1, string word2) {
     int sz1 = word1.size();
     int sz2 = word2.size();
     int pos1 = 0;
     int pos2 = 0;
     string merge;
     while (pos1 < sz1 || pos2 < sz2) {
       merge += largestSubstr(word1, sz1, pos1, word2, sz2, pos2);
     }

     return merge;
   }

 private:
   string largestSubstr(const string& s1, const int sz1, int& pos1, const string& s2, const int sz2, int& pos2) {
     string sub;
     if (pos1 >= sz1) {
       sub = s2.substr(pos2);
       pos2 = sz2;
       return  sub;
     }
     if (pos2 >= sz2) {
       sub = s1.substr(pos1);
       pos1 = sz1;
       return sub;
     }

     // 找出最长非降序共同前缀
     int i = 0;
     while (pos1 + i < sz1 && pos2 + i < sz2 && s1[pos1 + i] == s2[pos2 + i]) {
       if (i == 0 || s1[pos1 + i] >= s1[pos1 + i - 1]) {
         ++i;
       } else {
         break;
       }
     }
     // 没有非降序共同前缀
     if (i == 0) {
       if (s1[pos1] > s2[pos2]) {
         sub += s1[pos1];
         ++pos1;
       } else {
         sub += s2[pos2];
         ++pos2;
       }
       return sub;
     }
     // 最长非降序共同前缀的长度为i
     if (s1.substr(pos1 + i) > s2.substr(pos2 + i)) {
       sub = s1.substr(pos1, i);
       pos1 += i;
     } else {
       sub = s2.substr(pos2, i);
       pos2 += i;
     }
     return sub;
   }
};
