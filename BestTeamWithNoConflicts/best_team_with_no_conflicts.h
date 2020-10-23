/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/20
 *
 * Source : https://leetcode-cn.com/problems/best-team-with-no-conflicts/
 * Problem:	Best Team With No Conflicts
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int bestTeamScore(vector<int>& scores, vector<int>& ages) {
     int n = scores.size();
     vector<int64_t> vec(n);
     for (int i = 0; i < n; ++i) {
       int64_t age = ages[i];
       int64_t score = scores[i];
       vec[i] = (age << 32) | (score & 0xFFFFFFFF);
     }
     std::sort(vec.begin(), vec.end());

     vector<int> dp(n, 0);
     int best_score = 0;
     for (int i = 0; i < n; ++i) {
       int score = vec[i] & 0xFFFFFFFF;
       dp[i] = score;
       for (int j = 0; j < i; ++j) {
         if (score >= (vec[j] & 0xFFFFFFFF)) {
           dp[i] = std::max(dp[j] + score, dp[i]);
         }
       }
       best_score = std::max(best_score, dp[i]);
     }

     return best_score;
   }
};
