/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 * Problem:	Range Sum Query 2D - Immutable
 *
 */
#include <vector>
using std::vector;

class NumMatrix {
 public:
   NumMatrix(vector<vector<int> >& matrix) {
     row = matrix.size() + 1;
     col = (matrix.empty() ? 0 : matrix[0].size()) + 1;
     for (int i = 0; i < row; ++i) {
       m.push_back(vector<int>(col, 0));
     }
     for (int i = 1; i < row; ++i) {
       for (int j = 1; j < col; ++j) {
         m[i][j] = matrix[i - 1][j - 1] + m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
       }
     }
   }

   int sumRegion(int row1, int col1, int row2, int col2) {
     return m[row2 + 1][col2 + 1] - m[row2 + 1][col1] - m[row1][col2 + 1] + m[row1][col1];
   }
   
 private:
   int row;
   int col;
   vector<vector<int> > m;
};
