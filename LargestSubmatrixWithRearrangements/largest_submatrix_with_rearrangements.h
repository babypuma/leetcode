/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/26
 *
 * Source : https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/
 * Problem: Largest Submatrix With Rearrangements
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int largestSubmatrix(vector<vector<int> >& matrix) {
     int row = matrix.size();
     int col = matrix[0].size();
     vector<vector<int> > m(row, vector<int>(col, 0));
     for (int j = 0; j < col; ++j) {
       for (int i = 0; i < row; ++i) {
         m[i][j] = (matrix[i][j] == 0) ? 0 : (i > 0 ? m[i - 1][j] + 1 : 1);
       }
     }
     int ans = 0;
     for (int i = 0; i < row; ++i) {
       std::sort(m[i].begin(), m[i].end(), std::greater<int>());
       for (int j = 0; j < col; ++j) {
         ans = std::max(ans, m[i][j] * (j + 1));
       }
     }
     return ans;
   }
};
