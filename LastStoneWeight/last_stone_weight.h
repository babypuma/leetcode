/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/30
 *
 * Source : https://leetcode-cn.com/problems/last-stone-weight/
 * Problem:	Last Stone Weight
 *
 */
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

class Solution {
 public:
   int lastStoneWeight(vector<int>& stones) {
     priority_queue<int> que(stones.begin(), stones.end());
     while (que.size() > 1) {
       int w1 = que.top();
       que.pop();
       int w2 = que.top();
       que.pop();
       que.push(w1 - w2);
     }
     return que.top();
   }
};
