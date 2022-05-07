/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/06
 *
 * Source : https://leetcode-cn.com/problems/maximize-score-after-n-operations/
 * Problem:	Maximize Score After N Operations
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxScore(vector<int>& nums) {
     int sz = nums.size();
     for (int i = 0; i < sz; ++i) {
       for (int j = i + 1; j < sz; ++j) {
         gcd_[i][j] = gcd(nums[i], nums[j]);
       }
     }

     vector<int> dp(1 << sz, 0);
     return dfs(nums, sz, dp, 1, (1 << sz) - 1);
   }

 private:
   int dfs(const vector<int>& nums, const int sz, vector<int>& dp, int step, int state) {
     if (dp[state] != 0) {
       return dp[state];
     }

     for (int i = 0; i < sz; ++i) {
       for (int j = i + 1; j < sz; ++j) {
         if ((state & (1 << i)) && (state & (1 << j))) {
           int new_state = state ^ (1 << i) ^ (1 << j);
           dp[state] = std::max(dp[state], step * gcd_[i][j] + dfs(nums, sz, dp, step + 1, new_state));
         }
       }
     }
     return dp[state];
   }

   int gcd(int a, int b) {
     if (a % b == 0) {
       return b;
     }
     return gcd(b, a % b);
   }

 private:
   static const int MAX_NUM = 14;
   int gcd_[MAX_NUM + 1][MAX_NUM + 1];
};
