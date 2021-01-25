/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/25
 *
 * Source : https://leetcode-cn.com/problems/minimum-number-of-people-to-teach/
 * Problem: Minimum Number of People to Teach
 *               
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
   int minimumTeachings(int n, vector<vector<int> >& languages, vector<vector<int> >& friendships) {
     for (auto& lang : languages) {
       std::sort(lang.begin(), lang.end());
     }
     unordered_set<int> no_communication;
     unordered_map<int, int> common_languages;
     for (auto& f : friendships) {
       if (communicated(languages, f[0] - 1, f[1] - 1)) {
         continue;
       }
       no_communication.insert(f[0]);
       no_communication.insert(f[1]);
     }
     int ans = 0;
     for (auto& k : no_communication) {
       for (auto& l : languages[k - 1]) {
         ans = std::max(ans, ++common_languages[l]);
       }
     }

     return no_communication.size() - ans;
   }

 private:
   bool communicated(vector<vector<int> >& languages, int p1, int p2) {
     int i = 0;
     int j = 0;
     while (i < languages[p1].size() && j < languages[p2].size()) {
       if (languages[p1][i] == languages[p2][j]) {
         return true;
       }
       languages[p1][i] < languages[p2][j] ? ++i : ++j;
     }

     return false;
   }
};
