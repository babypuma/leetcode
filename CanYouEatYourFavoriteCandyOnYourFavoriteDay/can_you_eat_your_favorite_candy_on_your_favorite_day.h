/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/31
 *
 * Source : https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
 * Problem: Can You Eat Your Favorite Candy on Your Favorite Day
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<bool> canEat(vector<int>& candiesCount, vector<vector<int> >& queries) {
     int cand_num = candiesCount.size();
     vector<int64_t> total_candies(cand_num);
     total_candies[0] = candiesCount[0];
     for (int i = 1; i < cand_num; ++i) {
       total_candies[i] = total_candies[i - 1] + candiesCount[i];
     }

     int query_num = queries.size();
     vector<bool> answer(query_num, false);
     for (int i = 0; i < query_num; ++i) {
       int f_type = queries[i][0];
       int f_day = queries[i][1];
       int daily_cap = queries[i][2];
       int64_t max = static_cast<int64_t>(daily_cap) * (f_day + 1);
       if (total_candies[f_type] < (f_day + 1) || (f_type > 0 && max <= total_candies[f_type - 1])) {
         continue;
       }
       answer[i] = true;
     }
     return answer;
   }
};
