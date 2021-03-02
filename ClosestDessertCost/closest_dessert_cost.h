/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/01
 *
 * Source : https://leetcode-cn.com/problems/closest-dessert-cost/
 * Problem: Closest Dessert Cost
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
     vector<bool> cost(MAX_COST + 1, false);
     for (auto& base : baseCosts) {
       cost[base] = true;
     }

     for (auto& topping : toppingCosts) {
       for (int j = 0; j < 2; ++j) {
         for (int i = MAX_COST; i > topping; --i) {
           cost[i] = cost[i] || cost[i - topping];
         }
       }
     }

     int ans;
     int min_gap = INT_MAX;
     for (int i = 1; i <= MAX_COST; ++i) {
       if (cost[i] && std::abs(i - target) < min_gap) {
         ans = i;
         min_gap = std::abs(i - target);
       }
     }
     return ans;
   }

 private:
   static const int MAX_COST = 210000;
};
