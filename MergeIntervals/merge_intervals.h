/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/09
 *
 * Source : https://leetcode-cn.com/problems/merge-intervals/
 * Problem:	Merge Intervals
 *
 */
#include <vector>
#include <utility>
using std::vector;
using std::pair;

class Solution {
 public:
   vector<vector<int> > merge(vector<vector<int> >& intervals) {
     vector<pair<int, int> > section(MAX_NUMBER + 1, std::make_pair(0, 0));
     for (int i = 0; i < intervals.size(); ++i) {
       section[intervals[i][0]].first += BEGIN;
       section[intervals[i][1]].second += END;
     }

     vector<vector<int> > vec2;
     int begin = 0;
     int sum = 0;
     for (int i = 0; i < MAX_NUMBER + 1; ++i) {
       if (section[i].first == 0 && section[i].second == 0) {
         continue;
       }

       if (sum == 0 && sum + section[i].first < 0) {
         begin = i;
       } 
       sum += section[i].first;

       if (sum < 0 && sum + section[i].second == 0) {
         vec2.push_back(vector<int>());
         vec2.back().push_back(begin);
         vec2.back().push_back(i);
       }
       sum += section[i].second;
     }
     return vec2;
   }

 private:
   static const int MAX_NUMBER = 10000;
   static const int BEGIN = -1;
   static const int END = 1;
};
