/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/12
 *
 * Source : https://leetcode-cn.com/problems/most-common-word/
 * Problem:	Most Common Word
 *               
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::pair;

class Solution {
 public:
   string mostCommonWord(string paragraph, vector<string>& banned) {
     unordered_set<string> banned_words(banned.begin(), banned.end());
     unordered_map<string, int> word_count;
     pair<int, string> ans;
     size_t i = 0;
     while (i < paragraph.size()) {
       string word;
       while (i < paragraph.size() && !isalpha(paragraph[i])) {
         ++i;
       }
       if (i == paragraph.size()) {
         break;
       }

       word += tolower(paragraph[i]);
       ++i;
       while (i < paragraph.size() && isalpha(paragraph[i])) {
         word += tolower(paragraph[i]);
         ++i;
       }

       if (banned_words.find(word) == banned_words.end()) {
         int cnt = ++word_count[word];
         if (cnt > ans.first) {
           ans.first = cnt;
           ans.second = word;
         }
       }
     }
     return ans.second;
   }
};
