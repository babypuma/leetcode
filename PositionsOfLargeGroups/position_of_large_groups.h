/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/positions-of-large-groups/
 * Problem:	Positions of Large Groups
 *
 */
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
 public:
   vector<vector<int> > largeGroupPositions(string s) {
     vector<vector<int> > vec;
     int start = 0;
     for (int i = 1; i < s.size(); ++i) {
       if (s[i] != s[i - 1]) {
         if (i - start >= 3) {
           vector<int> v;
           v.push_back(start);
           v.push_back(i - 1);
           vec.push_back(v);
         }
         start = i;
       }
     }
     if (s.size() - start >= 3) {
       vector<int> v;
       v.push_back(start);
       v.push_back(s.size() - 1);
       vec.push_back(v);
     }
     return vec;
   }
};
