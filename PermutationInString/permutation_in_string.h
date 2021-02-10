/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/11
 *
 * Source : https://leetcode-cn.com/problems/permutation-in-string/
 * Problem: Permutation in String
 *               
 */
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
 public:
   bool checkInclusion(string s1, string s2) {
     int sz1 = s1.size();
     int sz2 = s2.size();
     if (sz1 > sz2) {
       return false;
     }
     unordered_map<char, int> const_mp;
     unordered_map<char, int> mp;
     for (auto& ch : s1) {
       ++const_mp[ch];
       ++mp[ch];
     }

     int left = 0;
     int right = 0;
     while (right < sz2) {
       if (mp.count(s2[right]) == 0) {
         ++right;
         left = right;
         mp = const_mp;
       } else if (mp[s2[right]] == 0) {
         ++mp[s2[left]];
         ++left;
       } else {
         --mp[s2[right]];
         ++right;
         if (right - left == sz1) {
           return true;
         }
       }
     }

     return false;
   }
};
