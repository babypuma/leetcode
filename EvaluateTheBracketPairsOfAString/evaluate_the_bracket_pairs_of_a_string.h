/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/28
 *
 * Source : https://leetcode-cn.com/problems/evaluate-the-bracket-pairs-of-a-string/
 * Problem: Evaluate the Bracket Pairs of a String
 *               
 */
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
 public:
   string evaluate(string s, vector<vector<string> >& knowledge) {
     unordered_map<string, string> knowledge_map;
     for (auto& v : knowledge) {
       knowledge_map[v[0]] = v[1];
     }
     string str;
     int sz = s.size();
     int left = 0;
     int right = 0;
     while (left < sz) {
       if (s[left] != '(') {
         str += s[left];
         ++left;
         continue;
       }
       right = left + 1;
       while (s[right] != ')') {
         ++right;
       }
       string key = s.substr(left + 1, right - left - 1);
       if (knowledge_map.count(key) > 0) {
         str.append(knowledge_map[key]);
       } else {
         str += '?';
       }
       left = right + 1;
     }

     return str;
   }
};
