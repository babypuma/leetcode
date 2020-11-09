/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/07
 *
 * Source : https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Problem:	Longest Palindromic Substring
 *
 */
#include <string>
#include <utility>
using std::string;
using std::make_pair;
using std::pair;

class Solution {
 public:
   string longestPalindrome(string s) {
     int left = 0;
     int right = 0;
     for (int i = 0; i < s.size(); ++i) {
       auto p1 = expandAroundCenter(s, i, i);
       auto p2 = expandAroundCenter(s, i, i + 1);
       if (p1.second - p1.first > right - left) {
         left = p1.first;
         right = p1.second;
       }
       if (p2.second - p2.first > right - left) {
         left = p2.first;
         right = p2.second;
       }
     }
     return s.substr(left, right - left + 1);
   }

 private:
   pair<int, int> expandAroundCenter(const string& s, int left, int right) {
     while (left >= 0 && right < s.size() && s[left] == s[right]) {
       --left;
       ++right;
     }
     return make_pair(left + 1, right - 1);
   }
};
