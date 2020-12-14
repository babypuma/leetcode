/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/verifying-an-alien-dictionary/
 * Problem: Verifying an Alien Dictionary
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
   bool isAlienSorted(vector<string>& words, string order) {
     unordered_map<char, int> alphabet;
     for (int i = 0; i < order.size(); ++i) {
       alphabet[order[i]] = i;
     }
     for (int i = 0; i < words.size() - 1; ++i) {
       if (!alienLess(words[i], words[i + 1], alphabet)) {
         return false;
       }
     }
     return true;
   }

 private:
   bool alienLess(const string& s1, const string& s2, unordered_map<char, int>& alphabet) {
     int sz = std::min(s1.size(), s2.size());
     for (int i = 0; i < sz; ++i) {
       if (alphabet[s1[i]] != alphabet[s2[i]]) {
         return alphabet[s1[i]] < alphabet[s2[i]];
       }
     }
     return s1.size() <= s2.size();
   }
};
