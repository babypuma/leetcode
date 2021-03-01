/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/01
 *
 * Source : https://leetcode-cn.com/problems/count-items-matching-a-rule/
 * Problem: Count Items Matching a Rule
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
   int countMatches(vector<vector<string> >& items, string ruleKey, string ruleValue) {
     unordered_map<string, int> freq;
     for (auto& v : items) {
       ++freq["type" + v[0]];
       ++freq["color" + v[1]];
       ++freq["name" + v[2]];
     }
     string key = ruleKey + ruleValue;
     return freq.count(key) == 0 ? 0 : freq[key];
   }
};
