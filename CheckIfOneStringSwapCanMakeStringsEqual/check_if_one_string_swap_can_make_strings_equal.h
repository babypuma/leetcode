/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/14
 *
 * Source : https://leetcode-cn.com/problems/check-if-one-string-swap-can-make-strings-equal/
 * Problem: Check if One String Swap Can Make Strings Equal
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   bool areAlmostEqual(string s1, string s2) {
     vector<int> diff;
     int sz = s1.size();
     for (int i = 0; i < sz; ++i) {
       if (s1[i] != s2[i]) {
         diff.push_back(i);
       }
     }
     return (diff.empty() || (diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]));
   }
};
