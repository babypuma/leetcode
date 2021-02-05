/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/reducing-dishes/
 * Problem: Reducing Dishes
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxSatisfaction(vector<int>& satisfaction) {
     std::sort(satisfaction.begin(), satisfaction.end());
     int sz = satisfaction.size();
     vector<int> suffix_sum(sz, 0);
     suffix_sum[sz - 1] = satisfaction[sz - 1];
     for (int i = sz - 2; i >= 0; --i) {
       suffix_sum[i] = suffix_sum[i + 1] + satisfaction[i];
     }
     int sat = 0;
     for (int i = sz - 1; i >= 0; --i) {
       if (suffix_sum[i] <= 0) {
         break;
       }
       sat += suffix_sum[i];
     }
     return sat;
   }
};
