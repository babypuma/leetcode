/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/30
 *
 * Source : https://leetcode.cn/problems/two-best-non-overlapping-events/
 * Problem:	Two Best Non-Overlapping Events
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
 public:
   int maxTwoEvents(vector<vector<int> >& events) {
     size_t sz = events.size();
     std::sort(events.begin(), events.end());
     vector<int> backMax(sz, 0);
     backMax.back() = events.back()[2];
     for (int i = sz - 2; i >= 0; --i) {
       backMax[i] = std::max(backMax[i + 1], events[i][2]);
     }

     int ans = 0;
     for (size_t i = 0; i < sz; ++i) {
       ans = std::max(ans, events[i][2]);
       vector<int> elem(3, 0);
       elem[0] = events[i][1] + 1;
       size_t pos = std::upper_bound(events.begin(), events.end(), elem)- events.begin();
       if (pos < sz) {
         ans = std::max(ans, backMax[pos] + events[i][2]);
       }
     }

     return ans;
   }
};
