/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2020/12/12
 *
 * Source : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * Problem:	Longest Substring Without Repeating Characters
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int lengthOfLongestSubstring(string s) {
     vector<int> char_set(256, -1);
     int ans = 0;
     int start = 0;
     int i = 0;
     while (i < s.size()) {
       while (i < s.size() && char_set[s[i]] < 0) {
         char_set[s[i]] = i;
         ++i;
       }
       ans = std::max(ans, i - start);

       if (i < s.size()) {
         int last_pos = char_set[s[i]];
         for (int j = start; j <= last_pos; ++j) {
           char_set[s[j]] = -1;
         }
         start = last_pos + 1;
       }
     }
     return ans;
   }
};
