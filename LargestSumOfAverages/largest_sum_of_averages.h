/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/15
 *
 * Source : https://leetcode-cn.com/problems/largest-sum-of-averages/
 * Problem:	Largest Sum of Averages
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   double largestSumOfAverages(vector<int>& A, int K) {
     int n = A.size();
     vector<vector<double> > sum(n, vector<double>(n, 0));
     // sum[i][j]表示A[i..j]的累加和, 用于求avg(A[i..j])) (i <= j)
     for (int i = 0; i < n; ++i) {
       sum[i][i] = A[i];
       for (int j = i + 1; j < n; ++j) {
         sum[i][j] = sum[i][j - 1] + A[j];
       }
     }
     // dp[i][k]表示A[i..n-1]上分为k组的子问题解
     // 求解顺序为k从1到K
     // dp[i][k] = max(dp[j][k-1] + avg(A[i..j-1])) (i < j)
     // dp[j][k-1]为已解决的子问题
     vector<vector<double> > dp(n, vector<double>(K + 1, 0));
     for (int i = 0; i < n; ++i) {
       dp[i][1] = sum[i][n - 1] / (n - i);
     }
     for (int k = 2; k < K + 1; ++k) {
       // len(A[i..n-1]) >= k  =>  i <= n-k
       for (int i = std::min(n - 1, n - k); i >= 0; --i) {
         // len(A[j..n-1]) >= k-1  =>  j <= n-k+1
         for (int j = i + 1; j <= n - k + 1; ++j) {
           double avg = sum[i][j - 1] / (j - i);
           dp[i][k] = std::max(dp[i][k],  (j < n ? dp[j][k - 1] : 0) + avg);
         }
       }
     }
     return dp[0][K];
   }
};
