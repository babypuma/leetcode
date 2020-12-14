/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/group-anagrams/
 * Problem:	Group Anagrams
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
   vector<vector<string> > groupAnagrams(vector<string>& strs) {
     unordered_map<string, int> group_map;
     vector<vector<string> > group_vec;
     for (size_t i = 0; i < strs.size(); ++i) {
       string key(strs[i]);
       std::sort(key.begin(), key.end());
       if (group_map.find(key) != group_map.end()) {
         group_vec[group_map[key]].push_back(strs[i]);
       } else {
         group_vec.push_back(vector<string>());
         group_vec.back().push_back(strs[i]);
         group_map[key] = group_vec.size() - 1;
       }
     }

     return group_vec;
   }
};
