/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/maximal-square/
 * Problem:	Maximal Square
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maximalSquare(vector<vector<char> >& matrix) {
     if (matrix.empty()) {
       return 0;
     }

     int m = matrix.size();
     int n = matrix[0].size();
     vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
     int len = 0;
     for (int i = 1; i < m + 1; ++i) {
       for (int j = 1; j < n + 1; ++j) {
         if (matrix[i - 1][j - 1] == '0') {
           dp[i][j] = 0;
         } else {
           dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
           if (len < dp[i][j]) {
             len = dp[i][j];
           }
         }
       }
     }

     return len * len;
   }
};
