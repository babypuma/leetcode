/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 * Update : 2020/12/09
 *
 * Source : https://leetcode-cn.com/problems/spiral-matrix/
 * Problem:	Spiral Matrix
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> spiralOrder(vector<vector<int> >& matrix) {
     vector<int> vec;
     int m = matrix.size();
     int n = matrix[0].size();
     drawCircle(matrix, 0, -1, n, m - 1, vec);
     return vec;
   }

 private:
   void drawCircle(const vector<vector<int> >& matrix, int horizonal_idx, int vertical_idx, int horizonal_step, int vertical_step, vector<int>& vec) {
     if (horizonal_step <= 0) {
       return;
     }
     for (int i = 0; i < horizonal_step;) {
       ++i;
       vec.push_back(matrix[horizonal_idx][vertical_idx + i]);
     }

     if (vertical_step <= 0) {
       return;
     }
     for (int i = 0; i < vertical_step;) {
       ++i;
       vec.push_back(matrix[horizonal_idx + i][vertical_idx + horizonal_step]);
     }

     if (horizonal_step - 1 <= 0) {
       return;
     }
     for (int i = 0; i < horizonal_step - 1;) {
       ++i;
       vec.push_back(matrix[horizonal_idx + vertical_step][vertical_idx + horizonal_step - i]);
     }

     if (vertical_step - 1 <= 0) {
       return;
     }
     for (int i = 0; i < vertical_step - 1;) {
       ++i;
       vec.push_back(matrix[horizonal_idx + vertical_step - i][vertical_idx + 1]);
     }
     drawCircle(matrix, horizonal_idx + 1, vertical_idx + 1, horizonal_step - 2, vertical_step - 2, vec);
   }
};
