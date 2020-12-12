/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/meeting-rooms-ii/
 * Problem:	Meeting Rooms II
 *               
 */
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

class Solution {
 public:
   int minMeetingRooms(vector<vector<int> >& intervals) {
     std::sort(intervals.begin(), intervals.end());
     priority_queue<int, std::vector<int>, std::greater<int> > que;
     for (size_t i = 0; i < intervals.size(); ++i) {
       if (!que.empty() && que.top() <= intervals[i][0]) {
         que.pop();
       }
       que.push(intervals[i][1]);
     }
     return que.size();
   }
};
