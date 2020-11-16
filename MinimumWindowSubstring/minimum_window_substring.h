/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/16
 *
 * Source : https://leetcode-cn.com/problems/minimum-window-substring/
 * Problem:	Minimum Window Substring
 *               
 */
#include <string>
#include <unordered_map>
#include <cctype>
using std::string;
using std::unordered_map;

class Solution {
 public:
   string minWindow(string s, string t) {
     unordered_map<int, int> orig;
     unordered_map<int, int> cnt;
     for (int i = 0; i < t.size(); ++i) {
       ++orig[t[i]];
     }

     int left = 0;
     int right = -1;
     int ans_left = 0;
     int ans_len = INT_MAX;
     while (right < static_cast<int>(s.size())) {
       right++;
       if (orig.find(s[right]) != orig.end()) {
         ++cnt[s[right]];
       }

       while (left <= right && validate(orig, cnt)) {
         if (ans_len > right - left + 1) {
           ans_left = left;
           ans_len = right - left + 1;
         }
         if (orig.find(s[left]) != orig.end()) {
           --cnt[s[left]];
         }
         ++left;
       }
     }

     return ans_len < INT_MAX ? s.substr(ans_left, ans_len) : "";
   }

 private:
   bool validate(unordered_map<int, int>& orig, unordered_map<int, int>& cnt) {
     for (auto& it: orig) {
       if (cnt[it.first] < it.second) {
         return false;
       }
     }
     return true;
   }
};
