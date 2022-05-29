/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/29
 *
 * Source : https://leetcode.cn/contest/weekly-contest-295/problems/rearrange-characters-to-make-target-string/
 * Problem:	Rearrange Characters to Make Target String
 *
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int rearrangeCharacters(string s, string target) {
     const int SZ = 'z' - 'a' + 1;
     vector<int> pt(SZ, 0);
     for (size_t i = 0; i < target.size(); ++i) {
       pt[target[i] - 'a']++;
     }

     vector<int> ps(SZ, 0);
     for (size_t i = 0; i < s.size(); ++i) {
       ps[s[i] - 'a']++;
     }

     int cnt = s.size() / target.size();
     for (size_t i = 0; i < SZ; ++i) {
       if (pt[i] == 0) {
         continue;
       }
       cnt = std::min(cnt, ps[i] / pt[i]);
     }

     return cnt;
   }
};
