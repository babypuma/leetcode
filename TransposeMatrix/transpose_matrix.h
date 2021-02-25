/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/25
 *
 * Source : https://leetcode-cn.com/problems/transpose-matrix/
 * Problem: Transpose Matrix
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<vector<int> > transpose(vector<vector<int> >& matrix) {
     int row = matrix.size();
     int col = matrix[0].size();
     vector<vector<int> > tr(col, vector<int>(row));
     for (int i = 0; i < row; ++i) {
       for (int j = 0; j < col; ++j) {
         tr[j][i] = matrix[i][j];
       }
     }
     return tr;
   }
};
