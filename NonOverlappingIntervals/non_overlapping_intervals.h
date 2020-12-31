/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/01
 *
 * Source : https://leetcode-cn.com/problems/non-overlapping-intervals/
 * Problem: Non-overlapping Intervals
 *               
 */
#include <vector>
using std::vector;

class Sorter {
 public:
   bool operator()(const vector<int>& v1, const vector<int>& v2) {
     return v1[1] < v2[1];
   }
};

class Solution {
 public:
   int eraseOverlapIntervals(vector<vector<int> >& intervals) {
     if (intervals.empty()) {
       return 0;
     }

     std::sort(intervals.begin(), intervals.end(), Sorter());
     int ans = 1;
     int right = intervals[0][1];
     int sz = intervals.size();
     for (int i = 1; i < sz; ++i) {
       if (intervals[i][0] >= right) {
         ++ans;
         right = intervals[i][1];
       }
     }
     return sz - ans;
   }
};
