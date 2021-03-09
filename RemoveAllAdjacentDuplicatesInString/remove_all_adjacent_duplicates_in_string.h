/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/09
 *
 * Source : https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * Problem: Remove All Adjacent Duplicates In String
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   string removeDuplicates(string S) {
     vector<char> vec;
     for (auto& ch : S) {
       if (!vec.empty() && vec.back() == ch) {
         vec.pop_back();
         continue;
       }
       vec.push_back(ch);
     }
     string no_dup;
     for (auto& ch : vec) {
       no_dup += ch;
     }
     return no_dup;
   }
};
