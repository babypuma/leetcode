/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/triangle/
 * Problem:	Triangle
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int minimumTotal(vector<vector<int> >& triangle) {
     if (triangle.empty()) {
       return 0;
     }
     int n = triangle.back().size();
     vector<int> dp(n, triangle[0][0]);
     for (int i = 1; i < n; ++i) {
       dp[i] = dp[i - 1] + triangle[i][i];
       for (int j = i - 1; j > 0; --j) {
         dp[j] = std::min(dp[j - 1], dp[j]) + triangle[i][j];
       }
       dp[0] += triangle[i][0];
     }
     int min = dp[0];
     for (int i = 1; i < n; ++i) {
       if (min > dp[i]) {
         min = dp[i];
       }
     }
     return min;
   }
};
