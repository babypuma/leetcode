/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/18
 *
 * Source : https://leetcode-cn.com/problems/find-the-difference/
 * Problem: Find the Difference
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   char findTheDifference(string s, string t) {
     int sum = 0;
     for (auto& ch : t) {
       sum += static_cast<int>(ch);
     }
     for (auto& ch : s) {
       sum -= static_cast<int>(ch);
     }
     return static_cast<int>(sum);
   }
};
