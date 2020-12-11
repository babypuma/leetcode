/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/11
 *
 * Source : https://leetcode-cn.com/problems/reorder-data-in-log-files/
 * Problem:	Reorder Data in Log Files
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
    vector<string> reorderLogFiles(vector<string>& logs) {
      vector<string> letter_logs;
      unordered_map<string, string> letter_map;
      vector<string> digit_logs;
      for (size_t i = 0; i < logs.size(); ++i) {
        string& log = logs[i];
        size_t sz = log.size();
        size_t j = 0;
        while (j < sz && log[j] != ' ') {
          ++j;
        }
        string identifier = log.substr(0, j);
        while (j < sz && log[j] == ' ') {
          ++j;
        }
        if (isalpha(log[j])) {
          string content = log.substr(j);
          string key(content + identifier);
          letter_logs.push_back(key);
          letter_map[key] = log;
        } else {
          digit_logs.push_back(log);
        }
      }
      if (!letter_logs.empty()) {
        std::sort(letter_logs.begin(), letter_logs.end());
      }
      vector<string> sorted_logs;
      for (size_t i = 0; i < letter_logs.size(); ++i) {
        sorted_logs.push_back(letter_map[letter_logs[i]]);
      }
      for (size_t i = 0; i < digit_logs.size(); ++i) {
        sorted_logs.push_back(digit_logs[i]);
      }

      return sorted_logs;
    }
};
