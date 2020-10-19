/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters/
 * Problem: Largest Substring Between Two Equal Characters
 *
 */
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::pair;

class Solution {
 public:
   int maxLengthBetweenEqualCharacters(string s) {
     int m = -1;
     vector<pair<int, int> > vec(26, pair<int, int>(-1, -1));
     for (size_t i = 0; i < s.size(); ++i) {
       int pos = static_cast<int>(s[i] - 'a');
       if (vec[pos].first == -1) {
         vec[pos].first = i;
       } else {
         vec[pos].second = i;
         m = std::max(m, vec[pos].second - vec[pos].first - 1);
       }
     }
     return m;
   }
};
