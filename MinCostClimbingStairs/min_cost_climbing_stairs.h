/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/21
 *
 * Source : https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * Problem: Min Cost Climbing Stairs
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
 public:
   int minCostClimbingStairs(vector<int>& cost) {
     vector<int> min(cost.size() + 1, 0);
     min[0] = cost[0];
     min[1] = cost[1];
     for (size_t i = 2; i < min.size(); ++i) {
       if (i < min.size() - 1) {
         min[i] = std::min(min[i - 1], min[i - 2]) + cost[i];
       } else {
         min[i] = std::min(min[i - 1], min[i - 2]);
       }
     }
     return min[min.size() - 1];
   }
};
