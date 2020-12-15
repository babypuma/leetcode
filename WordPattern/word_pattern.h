/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/word-pattern/
 * Problem: Word Pattern
 *               
 */
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
 public:
   bool wordPattern(string pattern, string s) {
     unordered_map<string, char> word2pat;
     unordered_map<char, string> pat2word;
     size_t word_idx = 0;
     size_t i = 0;
     while (i < s.size()) {
       while (i < s.size() && s[i] == ' ') {
         ++i;
       }
       if (i == s.size()) {
         break;
       }

       size_t j = i + 1;
       while (j < s.size() && s[j] != ' ') {
         ++j;
       }
       string word = s.substr(i, j - i);
       char pat = pattern[word_idx];
       if (word2pat.find(word) != word2pat.end()) {
         if (pat != word2pat[word]) {
           return false;
         }
       } else {
         word2pat[word] = pattern[word_idx];
       }

       if (pat2word.find(pat) != pat2word.end()) {
         if (word != pat2word[pat]) {
           return false;
         }
       } else {
         pat2word[pat] = word;
       }
       ++word_idx;
       i = j;
     }

     return word_idx == pattern.size();
   }
};
